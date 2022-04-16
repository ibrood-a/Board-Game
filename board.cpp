//
//  boardFunctions.c
//  lab10
//
//  Created by Jacob Kennedy on 4/14/22.
//

#include "board.hpp"

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

void board::addElements( int puzzleIn ) {

    // starting from end when reading int
    int row = 2;
    int column = 2;
    int currentIndex = 8;
    
    // storage container for puzzle
    deque<pair<int, int>> puzzle;
    
    // as long as input still has something
    while ( puzzleIn > 0 ) {
        // get the last digit
        int curDigit = puzzleIn % 10;
        
        // remove last tile
        puzzleIn /= 10;
        
        // push last tile onto stack
        puzzle.push_front( make_pair(curDigit, column) );
        
        if (curDigit == 0)
            this->zeroIndex = currentIndex;
        
        // do it in reverse since reading from the back
        column--;
        currentIndex--;
        if (column < 0) {
            row--;
            column = 2;
        }
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
    
    movesToSolve = inversionCount;
    return inversionCount;
}

bool board::isBoardSolvable() {
    // the puzzle is solvable if the number of inversions is even
    return (calculateInversions() % 2) == 0;
}

void board::moveUp() {
    
}

void board::moveDown() {
    
}

void board::moveLeft() {
    
}

void board::moveRight() {
    
}
