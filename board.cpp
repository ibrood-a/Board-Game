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
    int col = 0;
    for ( auto t : puzzle ) { // loop thru deque
        col++;
        cout << t << " ";
        
        // end of row
        if (col > 2) {
            col = 0;
            cout << endl;
        }
    }
    
    cout << endl;
}

void board::addElements( char* argv ) {
    // loop thru the size input
    for ( int i = 0; i < 9; i++) {
        // get the value for index i
        int curDigit = argv[i] - '0';
        if (curDigit == 0)
            this->zeroIndex = i;
    
        // push current item to back of puzzle
        puzzle.push_back( curDigit );
    }
}

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

bool board::isBoardSolvable() {
    return calculateInversions() % 2 == 0;
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
 
    return true;
}

void board::computeValidMoves() {
    if (moveType(moveMod::up))
        cout << "zero can be moved up" << endl;
    
    if (moveType(moveMod::right))
        cout << "zero can be moved right" << endl;
    
    if (moveType(moveMod::down))
        cout << "zero can be moved down" << endl;
    
    if (moveType(moveMod::left))
        cout << "zero can be moved left" << endl;
    
    cout << endl;
}
