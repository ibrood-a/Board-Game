//
//  boardFunctions.c
//  lab10
//
//  Created by Jacob Kennedy on 4/14/22.
//

#include "boardFunctions.hpp"

bool boardFunctions::isBoardSolvable(deque<tile>& board) {
    // the puzzle is solvable if the number of inversions is even
    return (calculateInversions(board) % 2) == 0;
}

int boardFunctions::calculateInversions(deque<tile>& board) {
    auto inversionCount = 0;
    for ( auto t1 = 0; t1 < board.size() - 1; t1++) {
        for ( auto t2 = t1 + 1; t2 < board.size(); t2++) {
            auto tile1 = board.at(t1), tile2 = board.at(t2);
            
            // we dont want to mess with the blank tile
            if (tile1.blankTile || tile2.blankTile)
                continue;
            
            // if tile 1 is greater than tile 2 we need to invert
            if (board.at(t1).curValue > board.at(t2).curValue) {
                //tile1.swap(tile2);
                //when solving swap these two tiles
                
                inversionCount++;
            }
        }
    }
    
    movesToSolve = inversionCount;
    return inversionCount;
}

void boardFunctions::addElements( deque<tile>& board, int puzzle ) {

    // starting from end when reading int
    int row = 3;
    int column = 3;
    
    // declare a temp tile that will be added to deque
    tile tempTile(0, 0, 0, false);
    
    // as long as input still has something
    while ( puzzle > 0 ) {
        // get the last digit
        int endingDigit = puzzle % 10;
        
        // remove last tile
        puzzle /= 10;
        
        // set the atributes of this tile note: int % 10 gets the ending digit
        tempTile = tile(column, row, endingDigit, endingDigit == 0);
        
        // push last tile onto stack
        board.push_front( tempTile );
        
        // do it in reverse since reading from the back
        column--;
        if (column < 1) {
            row--;
            column = 3;
        }
    }
}

void boardFunctions::print( deque<tile>& board ) {
    // loop thru every value in the deque
    for ( tile t : board ) { // loop thru deque
        cout << "value: " << t.curValue << " ";
        
        // no more room in this row
        if (t.curCol == 3)
            cout << endl;
    }
    
    cout << endl;
}
