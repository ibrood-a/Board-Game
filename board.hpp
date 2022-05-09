//
//  boardFunctions.h
//  lab10
//
//  Created by Jacob Kennedy on 4/14/22.
//

#ifndef boardFunctions_h
#define boardFunctions_h

#include <deque>
#include <iostream>
using namespace std;

class board {
public:
	int moveDir;
	int zeroIndex;
	int movesTaken;

	board* parent;
	deque<int> puzzle;

	board(char* argv) {
		moveDir = 0;
		zeroIndex = 0;
		movesTaken = 0;
		parent = nullptr;
		for (int i = 0; i < 9; i++) {
			// get the value for index i
			int curDigit = argv[i] - '0';

			// store all info needed for zero
			if (curDigit == 0)
				this->zeroIndex = i;

			// push current item to back of puzzle
			puzzle.push_back(curDigit);
		}
	}

	board(deque<int> tempPuzzle, int zeroIn) {
		moveDir = 0;
		movesTaken = 0;
		parent = nullptr;
		zeroIndex = zeroIn;
		puzzle = tempPuzzle;
	}

	// print out the vector as a 3x3 grid
	void print();

	// checks to see if inversions is even or odd
	bool isBoardSolvable();
	// count the number of inversions needed to solve (even is solvable odd is not)
	int calculateInversions();

	// print valid moves
	void printValidMoves();
	// can 0 be moved xxx?
	bool moveType(int moveDirection, bool addChild = false);
	// solve the puzzle and print each step
	void solvePuzzle(board goalBoard);

};

#endif /* boardFunctions_h */
