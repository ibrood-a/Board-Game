//
//  boardFunctions.c
//  lab10
//
//  Created by Jacob Kennedy on 4/14/22.
//

#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board.hpp"
#include "helperFunctions.hpp"

void board::print() {
	int col = 0, row = 0;

	// print top border
	cout << ".---------." << endl;

	// loop thru each value of puzzle
	for (auto t : puzzle) {

		// print value prefix and postfix build box
		cout << prefix(col) << t << postfix(col);

		// end of this row
		if (col >= 2)
			cout << endl;

		// increment row and col counter
		col = (col >= 2) ? 0 : col + 1;
		row = (col >= 2) ? row + 1 : row;
	}

	// print the bottom border
	cout << "._________." << endl << endl;
}

// calculate the number of inversions
int board::calculateInversions() {
	int inversionCount = 0;
	for (auto t1 = 0; t1 < puzzle.size() - 1; t1++) {
		for (auto t2 = t1 + 1; t2 < puzzle.size(); t2++) {

			// if either tile is our zero just check next
			if (t1 == zeroIndex || t2 == zeroIndex)
				continue;

			//if tile 1 is greater than tile 2 we need to invert
			if (puzzle.at(t1) > puzzle.at(t2))
				inversionCount++;
		}
	}

	return inversionCount;
}

// board is not solvable if inversions are odd
bool board::isBoardSolvable() {
	return calculateInversions() % 2 == 0;
}

// modDistance is a value from moveMod
// addChild determines
bool board::moveType(int moveDirection, bool solvingPuzzle) {

	// cant move up in first row 0-2
	if (moveDirection == moveTypes::up && zeroIndex <= 2)
		return false;

	// cant move down in bottom row 6-8
	if (moveDirection == moveTypes::down && zeroIndex >= 6)
		return false;

	// cant move left if in first column (modulo 3 = 0)
	if (moveDirection == moveTypes::left && zeroIndex % 3 == 0)
		return false;

	// cant move right if in last column (modulo 3 = 2)
	if (moveDirection == moveTypes::right && zeroIndex % 3 == 2)
		return false;

	// zero offset value 
	int zeroOffset = moveModifier[moveDirection];

	// create new puzzle and swap
	auto tempPuzzle = puzzle;
	swap(tempPuzzle[zeroIndex], tempPuzzle[zeroIndex + zeroOffset]);

	// arent adding the child or its been tested
	if (!solvingPuzzle || previouslyTested(tempPuzzle))
		return true;

	// create the new board using updated zero pos
	board* tempBoard = new board(tempPuzzle, zeroIndex + zeroOffset);

	// set the parent and add it to list to test
	tempBoard->parent = this;
	tempBoard->moveDir = moveDirection;
	tempBoard->movesTaken = this->movesTaken + 1;

	// add to boards we need to test
	testBoards.push_back(tempBoard);

	// free memory
	tempBoard = nullptr;
	delete tempBoard;

	return true;
}

// addChild is used to determine if we are solving
// or just finding all directions we can move zero
void board::printValidMoves() {

	// loop thru all the directions (up, down, left, right) and print each that can be done
	for (auto tempMove : { moveTypes::up, moveTypes::down, moveTypes::right, moveTypes::left }) {
		// if this is a valid move print this to console
		if (moveType(tempMove, false))
			cout << "zero can be moved " << directionStr(tempMove) << endl;
	}

	cout << endl;
}

// recursively prints the path backwards
void printPath(board* b) {
	// initial state
	if (b == nullptr)
		return;

	// print the current step
	cout << "step " << b->movesTaken;
	if (b->parent != nullptr) // only show step if it isnt initial board
		cout << " was achieved by moving " << directionStr(b->moveDir) << endl;
	else
		cout << endl;

	b->print();

	// recursivly call using b's parent
	printPath(b->parent);
}

void board::solvePuzzle(board goalBoard) {

	// add the initial board
	testBoards.push_back(this);

	// keep looping until we find an answer
	while (!testBoards.empty()) {
		auto min = testBoards.front();
		testBoards.pop_front();

		// remember we tested min
		checkedBoards.push_back(min);

		// found the goal state with this board
		if (min->puzzle == goalBoard.puzzle) {
			// print the path
			printPath(min);

			// clear up the memory
			testBoards.clear();
			checkedBoards.clear();

			// we found the solution so just end here
			return;
		}

		// compute a move in each direction for min and add the children to testBoards
		for (auto tempMove : { moveTypes::up, moveTypes::down, moveTypes::right, moveTypes::left })
			min->moveType(tempMove, true);
	}

	return;
}
