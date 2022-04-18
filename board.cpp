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
        
        this->thisIndex = currentIndex;
        
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

bool board::moveUp() {
    if (zeroIndex <= 2)
        return false;
    
    auto temp = puzzle;
    swap(temp[zeroIndex], temp[zeroIndex - 3]);
    
    board* tempBoard = new board(temp, zeroIndex - 3);
    children.push_back(tempBoard);
    return true;
}

bool board::moveDown() {
    if (zeroIndex >= 6)
        return false;
    
    auto temp = puzzle;
    swap(temp[zeroIndex], temp[zeroIndex + 3]);
    
    board* tempBoard = new board(temp, zeroIndex + 3);
    children.push_back(tempBoard);
    return true;
}

bool board::moveLeft() {
    if (zeroIndex % 3 == 0)
        return false;
    
    auto temp = puzzle;
    swap(temp[zeroIndex], temp[zeroIndex - 1]);
    
    board* tempBoard = new board(temp, zeroIndex - 1);
    children.push_back(tempBoard);
    return true;
}

bool board::moveRight() {
    if (zeroIndex % 3 >= 2)
        return false;
    
    auto temp = puzzle;
    swap(temp[zeroIndex], temp[zeroIndex + 1]);
    
    board* tempBoard = new board(temp, zeroIndex + 1);
    children.push_back(tempBoard);
    return true;
}

void board::validMoves() {
    if (moveUp())
        cout << "zero can be moved up" << endl;
    
    if (moveRight())
        cout << "zero can be moved right" << endl;
    
    if (moveDown())
        cout << "zero can be moved down" << endl;
    
    if (moveLeft())
        cout << "zero can be moved left" << endl;
    
    cout << endl;
}
