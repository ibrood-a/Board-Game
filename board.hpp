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

// more than likely will need this later

class board {
public:
    int zeroIndex;
    board* parent;
    deque<board*> children;
    deque<pair<int, int>> puzzle;
    
    board() { }
    board(board* parentIn, int zeroIn) {
        parent = parentIn;
        zeroIndex = zeroIn;
    }
    
    // print out the vector as a 3x3 grid
    void print( );
    
    // function used to convert a single number into a vector of size 9 with single digit values
    void addElements( int puzzle );

    // count the number of inversions needed to solve (even is solvable odd is not)
    int calculateInversions();

    // checks to see if inversions is even or odd
    bool isBoardSolvable();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    
    int movesToSolve = 0;

}; extern board boardHelpers;

#endif /* boardFunctions_h */
