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
    
    board* parent;
    deque<int> puzzle;

    board() {}
    
    board(deque<int> tempPuzzle, int zeroIn) {
        zeroIndex = zeroIn;
        puzzle = tempPuzzle;
    }
    
    // print out the vector as a 3x3 grid
    void print( );
    // function used to convert a single number into a vector of size 9 with single digit values
    void addElements( char* argv );
    
    // checks to see if inversions is even or odd
    bool isBoardSolvable();
    // count the number of inversions needed to solve (even is solvable odd is not)
    int calculateInversions();
    
    // can 0 be moved xxx?
    bool moveType(int modDistance);
    // print valid moves
    void computeValidMoves();

};

#endif /* boardFunctions_h */
