// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "board.hpp"

using namespace std;

int main(int argc, char** argv) {

	// add all the elements
	board testBoard(argv[1]);
	board goalBoard(argv[2]);

	// print the board
	cout << "INITIAL BOARD" << endl;
	testBoard.print();

	// print goal boar
	cout << "GOAL BOARD" << endl;
	goalBoard.print();

	// solve the testBoard using the goalBoard
	testBoard.solvePuzzle(goalBoard);

	return 0;
}
