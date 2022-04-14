// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "boardFunctions.hpp"

using namespace std;
boardFunctions boardHelpers;

int main( int argc, char** argv ) {
    deque<tile> board; // vector for the puzzle
	string arg1( argv[ 1 ] ); // string containing the value of command line 

	// add all the elements to the vector
    boardHelpers.addElements( board, stoi( arg1 ) );

    // debugging purposes
    boardHelpers.print( board );
    
    if (boardHelpers.isBoardSolvable(board))
        cout << "Solvable with " << boardHelpers.movesToSolve << " moves" << endl;
    else
        cout << "This board is not solvable" << endl;
}
