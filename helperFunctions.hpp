//
//  helperFunctions.h
//  lab10
//
//  Created by Jacob Kennedy on 4/24/22.
//

#ifndef helperFunctions_h
#define helperFunctions_h
#include <deque>
#include "board.hpp"

using namespace std;

enum moveMod {
    up = -3,
    right = 1,
    down = 3,
    left = -1,
};

extern deque<board*> testBoards;
extern deque<board*> checkedBoards;

string prefix(int col);
string postfix(int col);
string directionStr(int m);

bool previouslyTested(deque<int> testBoard);

bool operator==( const deque<int> lhs, const deque<int> rhs );

#endif /* helperFunctions_h */
