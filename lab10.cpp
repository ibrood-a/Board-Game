// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <deque>
#include <stack>

using namespace std;

struct tile {
    int curCol;
    int curRow;
    int curValue;
    
    tile(int col, int row, int val) {
        curCol = col;
        curRow = row;
        curValue = val;
    }
};

// print out the vector as a 3x3 grid
void print( deque<tile>& vec );

// function used to convert a single number into a vector of size 9 with single digit values
void addElements( deque<tile>& test, int puzzle );

int main( int argc, char** argv ) {
    deque<tile> puzzleVec; // vector for the puzzle
    string arg1( argv[ 1 ] ); // string containing the value of command line

    // add all the elements to the vector
    addElements( puzzleVec, stoi( arg1 ) );

    print( puzzleVec );
}

void addElements( deque<tile>& test, int puzzle ) {

    int row = 3;
    int column = 3;
    tile tempTile(0, 0, 0);
    
    // as long as input still has something
    while ( puzzle > 0 ) {
        // set the atributes of this tile note: int % 10 gets the ending digit
        tempTile = tile(column, row, puzzle % 10);
        
        // push last tile onto stack
        test.emplace_front( tempTile );
        
        // remove last tile
        puzzle /= 10;
        
        // gotta do it in reverse since reading from the back
        column--;
        if (column < 1) {
            row--;
            column = 3;
        }
    }
}

void print( deque<tile>& vec ) {
    int rowIndex = 0;
    for ( tile v : vec ) { // loop thru vector

        if ( rowIndex < 3 ) { // only 3 items per row
            cout << "value: " << v.curValue
            << " row: " << v.curRow
            << " column: " << v.curCol << " ";
            rowIndex++;
        }
        else { // 3 items met reset and go to next row
            rowIndex = 1;
            cout << endl << "value: " << v.curValue
            << " row: " << v.curRow
            << " column: " << v.curCol << " ";
        }
    }
    
    cout << endl;
}


/* valid moves *//*

 validMoves(const board testBoard) {
    // where is the blank (0)
    int blankRow = 0;
    int blankCol = 0;
    
    // if this move
 }
 */
