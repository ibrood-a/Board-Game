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
class tile {
public:
    int curCol;
    int curRow;
    int curValue;
    bool blankTile;
    
    tile(int col, int row, int val, bool blank) {
        curCol = col;
        curRow = row;
        curValue = val;
        blankTile = blank;
    }
    
    void swap(tile otherTile);
};

class boardFunctions {
public:
    // checks to see if inversions is even or odd
    bool isBoardSolvable(deque<tile>& board);

    // count the number of inversions needed to solve (even is solvable odd is not)
    int calculateInversions(deque<tile>& board);

    // function used to convert a single number into a vector of size 9 with single digit values
    void addElements( deque<tile>& board, int puzzle );

    // print out the vector as a 3x3 grid
    void print( deque<tile>& board );
    
    int movesToSolve = 0;

}; extern boardFunctions boardHelpers;

#endif /* boardFunctions_h */
