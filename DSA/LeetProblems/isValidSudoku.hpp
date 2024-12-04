// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.


#pragma once
#include<vector>
#include<unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    // create unordered_sets for rows, columns and sub-boxes
    const int SIZE = 9;
    std::vector<std::unordered_set<char>> rows(SIZE);
    std::vector<std::unordered_set<char>> cols(SIZE);
    std::vector<std::unordered_set<char>> boxes(SIZE);

    // size of sudoku is fixed, but for generalized solution
    for(int r = 0; r < SIZE; ++r){
        for(int c = 0; c < SIZE; ++c){
            char cell = board[r][c];
            if(cell == '.') continue; // skip empty cells

            int boxIdx = (r / 3) * 3 + (c / 3); // index of sub-box

            // check for duplicate in row, column or sub-box
            if(rows[r].count(cell) || cols[c].count(cell) || boxes[boxIdx].count(cell)) return false;
            
            // insert the current cell
            rows[r].insert(cell);
            cols[c].insert(cell);
            boxes[boxIdx].insert(cell);
        }

    }
    return true; 
}