// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "board.hpp"

using namespace std;
board testBoard, testBoard2;

int main( int argc, char** argv ) {

	// add all the elements
    testBoard.addElements( argv[ 1 ] );
    testBoard2.addElements( argv[ 2 ] );

    // if there are duplicate numbers then we dont want to test it
    if (testBoard.duplicateNumbers || testBoard2.duplicateNumbers)
        return 0;
    
    // print the board
    testBoard.print( );
    // see what moves are valid
    testBoard.validMoves();
    // check if it is solvable
    testBoard.isBoardSolvable();
    
    // print second board
    testBoard2.print( );
    // test valid moves here too
    testBoard2.validMoves();
    // check if it is solvable
    testBoard2.isBoardSolvable();
    
    return 0;
}
