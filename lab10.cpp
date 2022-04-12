// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// print out the vector as a 3x3 grid
void print( vector<int>& vec );

// function used to convert a single number into a vector of size 9 with single digit values
void addElements( vector<int>& test, int puzzle );

int main( int argc, char** argv ) {
	vector<int> puzzleVec; // vector for the puzzle
	string arg1( argv[ 1 ] ); // string containing the value of command line 

	// add all the elements to the vector
	addElements( puzzleVec, stoi( arg1 ) );

	print( puzzleVec );
}

void print( vector<int>& vec ) {
	int rowIndex = 0; 
	for ( int v : vec ) { // loop thru vector

		if ( rowIndex < 3 ) { // only 3 items per row
			cout << v << " ";
			rowIndex++;
		}
		else { // 3 items met reset and go to next row
			rowIndex = 1;
			cout << endl << v << " ";
		}
	}
}

void addElements( vector<int>& test, int puzzle ) {

	// as long as input still has something
	stack<int> st;
	while ( puzzle > 0 ) {
		st.push( puzzle % 10 ); // push last digit onto stack
		puzzle /= 10; // remove last digit
	}

	// run thru the stack in reverse to put our list in correct order
	// ex. 1234 currently is 4321 in the stack so push the top to back of vector to un-reverse
	while ( !st.empty( ) ) {
		test.push_back( st.top( ) );
		st.pop( );
	}
}