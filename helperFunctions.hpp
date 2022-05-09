//
//  helperFunctions.h
//  lab10
//
//  Created by Jacob Kennedy on 4/24/22.
//

#ifndef helperFunctions_h
#define helperFunctions_h
#include <map>
#include <deque>
#include "board.hpp"

using namespace std;

// types of moves indexed
enum moveTypes {
	up = 0,
	down, 
	left,
	right
};

// <index, modifier> map of values for move offset
extern map<int, int> moveModifier;

// storage containers for boards to test and boards we have tested
extern deque<board*> testBoards;
extern deque<board*> checkedBoards;

// function that outputs the prefix for the value that needs to be printed 
string prefix(int col);
// function that outputs the postfix for the value that needs to be printed
string postfix(int col);
// get the direction that we are moving zero based on an integer
string directionStr(int m);

bool previouslyTested(deque<int> testBoard);

// overloading the comparison operator to be able to test different puzzles
bool operator==(const deque<int> lhs, const deque<int> rhs);

#endif /* helperFunctions_h */
