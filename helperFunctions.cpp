//
//  helperFunctions.cpp
//  lab10
//
//  Created by Jacob Kennedy on 4/24/22.
//

#include "helperFunctions.hpp"

deque<board*> testBoards;
deque<board*> checkedBoards;

string prefix(int col) {
    switch (col) {
        case 0:
            return "| ";
        default:
            return " ";
    }
    
    return "";
}

string postfix(int col) {
    switch (col) {
        case 2:
            return " |";
        default:
            return " ";
    }
    
    return "";
}

string directionStr(int m) {
    switch (m) {
        case moveMod::up:
            return "up";
        case moveMod::down:
            return "down";
        case moveMod::left:
            return "left";
        case moveMod::right:
            return "right";
    }
    
    return "";
}

bool previouslyTested(deque<int> testBoard) {
    // loop thru all the boards we have tested
    for (auto it : checkedBoards)
        if (it->puzzle == testBoard) // if tested before
            return true; // return true
    
    return false; // return false (no result found)
}

bool operator==( const deque<int> lhs, const deque<int> rhs ) {
    for (int i = 0; i < 9; i++)
        if (lhs[i] != rhs[i])
            return false;
    
    return true;
}
