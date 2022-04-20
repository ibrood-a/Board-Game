//
//  boardFunctions.c
//  lab10
//
//  Created by Jacob Kennedy on 4/14/22.
//

#include "board.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int upMod = -3;
int downMod = 3;
int rightMod = 1;
int leftMod = -1;

void board::print() {
    // loop thru every value in the deque
    for ( auto t : puzzle ) { // loop thru deque
        cout << t.first << " ";
        
        // no more room in this row
        if (t.second == 2)
            cout << endl;
    }
    
    cout << endl;
}

void board::addElements( char* argv ) {

    // starting from end when reading int
    int row = 0;
    int column = 0;
    
    // storage container for puzzle
    deque<pair<int, int>> puzzle;
    
    // as long as input still has something
    for ( int i = 0; i < 9; i++) {
        
        // get the last digit
        int curDigit = (int)(argv[i] - '0');
        
        if (numberFound[curDigit]) {
            duplicateNumbers = true;
            cout << "duplicate numbers in the puzzle" << endl << endl;
            break;
        }
        
        // push current item to back of puzzle
        puzzle.push_back( make_pair(curDigit, column) );
        
        if (curDigit == 0)
            this->zeroIndex = i;
        
        // for printing later on
        column++;
        if (column > 2) {
            row++;
            column = 0;
        }
        
        numberFound[curDigit] = true;
    }
    
    this->puzzle = puzzle;
}

int board::calculateInversions() {
    auto inversionCount = 0;
    for ( auto t1 = 0; t1 < puzzle.size() - 1; t1++) {
        for ( auto t2 = t1 + 1; t2 < puzzle.size(); t2++) {
            
            // if either tile is our zero just check next
            if (t1 == zeroIndex || t2 == zeroIndex)
                continue;
            
            //if tile 1 is greater than tile 2 we need to invert
            if (puzzle.at(t1).first > puzzle.at(t2).first)
                inversionCount++;
        }
    }
    
    return inversionCount;
}

void board::isBoardSolvable() {
    // the puzzle is solvable if the number of inversions is even
    if (calculateInversions() % 2 == 0)
        cout << "This board is solvable" << endl << endl;
    else
        cout << "This board is not solvable" << endl << endl;
}

bool board::moveType(int modDistance) {
    switch (modDistance) {
        case -3: // up
            if (zeroIndex <= 2)
                return false;
            break;
            
        case 3: // down
            if (zeroIndex >= 6)
                return false;
            break;
            
        case -1: // left
            if (zeroIndex % 3 == 0)
                return false;
            break;
            
        case 1: // right
            if (zeroIndex % 3 >= 2)
                return false;
            break;
    }
    
    auto temp = puzzle;
    swap(temp[zeroIndex], temp[zeroIndex + modDistance]);
    
    board* tempBoard = new board(temp, zeroIndex + modDistance);
    tempBoard->parent = this;
    
    children.push_back(tempBoard);
    return true;
}

void board::validMoves() {
    if (moveType(upMod))
        cout << "zero can be moved up" << endl;
    
    if (moveType(rightMod))
        cout << "zero can be moved right" << endl;
    
    if (moveType(downMod))
        cout << "zero can be moved down" << endl;
    
    if (moveType(leftMod))
        cout << "zero can be moved left" << endl;
}

void board::solvePuzzle(board* goalBoard) {
     /**
      step 1: create a way to store all of the puzzles we have tested
      step 2: create a way to see if we have tested a puzzle before adding it to a list of puzzles to test
      step 3: generate all posibilties based on the current puzzle we have
      step 4: test those posibilities to see if they are the correct one
      step 5: if we dont have any branch off of these tables and generate posibilities for each
      step 6: use function from step 2 to see if we have tested any of the newly generated puzzles
      step 7: compare to see if we have the correct goal
      step 8: repeat.
    */
}
