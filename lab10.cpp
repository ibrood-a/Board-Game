// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "board.hpp"

using namespace std;
board testBoard, testBoard2;

int main( int argc, char** argv ) {
	string testState( argv[ 1 ] ); // string containing value 1 of command line
    string testState2( argv[ 2 ] ); // string containing value 2 of command line

	// add all the elements
    testBoard.addElements( stoi( testState ) );
    testBoard2.addElements( stoi( testState2 ) );

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
    
}
