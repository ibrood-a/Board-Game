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
bool board::moveType(int moveDistance, bool solvingPuzzle) {

    // cant move up in first row 0-2
    if (moveDistance == moveMod::up && zeroIndex <= 2)
        return false;
   
    // cant move down in bottom row 6-8
    if (moveDistance == moveMod::down && zeroIndex >= 6)
        return false;
   
    // cant move left if in first column (modulo 3 = 0)
    if (moveDistance == moveMod::left && zeroIndex % 3 == 0)
        return false;
    
    // cant move right if in last column (modulo 3 = 2)
    if (moveDistance == moveMod::right && zeroIndex % 3 == 2)
        return false;

    // create new puzzle using the current board but
    // std::swap the zeroIndex and the index zero is being moved to
    
    
    // if we arent solving the puzzle or we have previously tested this just return
    // if (!solvingPuzzle || previouslyTested(tempPuzzle))
    //    return true;
    
    
    // create the new board using updated board (update zero index too)
    
    
    // set the parent and add it to list to test
    // increment moves taken
    
    
    // add to boards we need to test
    
    
    // free memory
    
    return true;
}

// addChild is used to determine if we are solving
// or just finding all directions we can move zero
void board::printValidMoves() {
    
    // loop thru all the directions (up, down, left, right) and print each that can be done
    for (auto moveDir : {moveMod::up, moveMod::down, moveMod::right, moveMod::left}) {
        // if this is a valid move print this to console
        if (moveType(moveDir, false))
            cout << "zero can be moved " << directionStr(moveDir) << endl;
    }
    
    cout << endl;
}

// recursively prints the path backwards
void printPath(board* b) {
    // if b is nullptr return because this is the starting board
    
    // print the current step
    
    // recursivly call using b's parent
}

void board::solvePuzzle(board goalBoard) {

    // add the initial board
    
    // keep looping until we run out of boards to test
    {
        
        // store the board in the front of testBoards
        
        // remove the board from the front of test boards
        
        // store a record that we are testing this board
        
        // if this board matches the goal board
        {
            // print the path
            
            // clear up the memory
            
            // we found the solution so just
            // return;
        }
        
        // loop thru all possible valid moves and add the valid ones to be tested
    }
    
    return;
}
