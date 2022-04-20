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
    int zeroIndex;
    int thisIndex;
    bool numberFound[9];
    bool duplicateNumbers;
    
    board* parent;
    deque<board*> children;
    deque<pair<int, int>> puzzle;
    
    board() { }
    board(deque<pair<int, int>> tempPuzzle, int zeroIn) {
        zeroIndex = zeroIn;
        puzzle = tempPuzzle;
    }
    
    // print out the vector as a 3x3 grid
    void print( );
    // function used to convert a single number into a vector of size 9 with single digit values
    void addElements( char* argv );
    // count the number of inversions needed to solve (even is solvable odd is not)
    int calculateInversions();
    // checks to see if inversions is even or odd
    bool isBoardSolvable();
    // can 0 be moved xxx?
    bool moveType(int modDistance);
    // print valid moves
    void validMoves();
    // solve the puzzle and print each step
    void solvePuzzle(board* goalBoard);

};

#endif /* boardFunctions_h */
