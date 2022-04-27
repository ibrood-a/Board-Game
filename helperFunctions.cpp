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

bool previouslyTested(deque<int> testBoard) {
    // loop thru all the boards we have tested
    // if tested before return true
    
    // return false (no result found)
    return false;
}

bool operator==( const deque<int> lhs, const deque<int> rhs ) {
    // loop thru all indexes
    // if left at index != right at index
    // return false because puzzles are not identical
    
    return true;
}
