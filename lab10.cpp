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

    if (testBoard.duplicateNumbers || testBoard2.duplicateNumbers)
        return 0;
    
    // print the board
    testBoard.print( );
    // see what moves are valid
    testBoard.validMoves();
    
    if (testBoard.isBoardSolvable())
        cout << "This board is solvable" << endl << endl;
    else
        cout << "This board is not solvable" << endl << endl;
    
    // print second board
    testBoard2.print( );
    // test valid moves here too
    testBoard2.validMoves();
    
    if (testBoard2.isBoardSolvable())
        cout << "This board is solvable" << endl << endl;
    else
        cout << "This board is not solvable" << endl << endl;
    
    return 0;
}
