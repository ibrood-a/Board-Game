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
    for ( auto t : puzzle ) {
        
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

// create the board from the input
void board::addElements( char* argv ) {
    for ( int i = 0; i < 9; i++) {
        // get the value for index i
        int curDigit = argv[i] - '0';
        
        // store all info needed for zero
        if (curDigit == 0)
            this->zeroIndex = i;
        
        // push current item to back of puzzle
        puzzle.push_back( curDigit );
    }
}

// calculate the number of inversions
int board::calculateInversions() {
    int inversionCount = 0;
    for ( auto t1 = 0; t1 < puzzle.size() - 1; t1++) {
        for ( auto t2 = t1 + 1; t2 < puzzle.size(); t2++) {
            
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
bool board::moveType(int modDistance, bool solvingPuzzle) {

    // cant move up in first row 0-2
    if (modDistance == moveMod::up && zeroIndex <= 2)
        return false;
   
    // cant move down in bottom row 6-8
    if (modDistance == moveMod::down && zeroIndex >= 6)
        return false;
   
    // cant move left if in first column (modulo 3 = 0)
    if (modDistance == moveMod::left && zeroIndex % 3 == 0)
        return false;
    
    // cant move right if in last column (modulo 3 = 2)
    if (modDistance == moveMod::right && zeroIndex % 3 == 2)
        return false;

    // create new puzzle and swap

    
    // if we arent solving or its been tested
    // return true (we dont want to add child here)

    
    // create the new board using updated zero pos
    
    
    // set the parent and add it to list to test
    // increment the moves taken
    
    
    // add to boards we need to test

    
    // free memory
    
    
    return true;
}

// addChild is used to determine if we are solving
// or just finding all directions we can move zero
void board::computeValidMoves(bool solvingPuzzle) {
    // if we can move and we arent solving puzzle
    if (moveType(moveMod::up, solvingPuzzle) && solvingPuzzle == false)
        cout << "zero can be moved up" << endl;
    
    if (moveType(moveMod::right, solvingPuzzle) && solvingPuzzle == false)
        cout << "zero can be moved right" << endl;
    
    if (moveType(moveMod::down, solvingPuzzle) && solvingPuzzle == false)
        cout << "zero can be moved down" << endl;
    
    if (moveType(moveMod::left, solvingPuzzle) && solvingPuzzle == false)
        cout << "zero can be moved left" << endl;
    
    if (solvingPuzzle == false)
        cout << endl;
}

// recursively prints the path backwards
void printPath(board* b) {
    // initial state
    if (b == nullptr)
        return;
    
    // print the current step
    
    // recursivly call printPath using b's parent board
}

void board::solvePuzzle(board goalBoard) {

    // add the initial board
    
    // until we run out of boards to test
    {
        // store the front puzzle thisBoard
        // remove the front puzzle from testBoards
        
        // store record of testing thisBoard
        
        // if we found the goal state with this board
        {
            // print the path
            
            // clear up the memory
            // return since puzzle is solved
        }
        
        // compute moves and add the children
    }
    
    return;
}
