// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "board.hpp"

using namespace std;
board testBoard, testBoard2;

int main( int argc, char** argv ) {
	string arg1( argv[ 1 ] ); // string containing the value of command line

	// add all the elements to the vector
    testBoard.addElements( stoi( arg1 ) );

    // debugging purposes
    testBoard.print( );
    
    testBoard.validMoves();
    
    if (testBoard.isBoardSolvable())
        cout << "Solvable with " << testBoard.movesToSolve << " moves" << endl;
    else
        cout << "This board is not solvable" << endl << endl;
    
}
