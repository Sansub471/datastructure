

bool isValidSudoku(vector<vector<char>>& board) {
    // create unordered_sets for rows, columns and sub-boxes
    const int SIZE = 9;
    vector<unordered_set<char>> rows(SIZE);
    vector<unordered_set<char>> cols(SIZE);
    vector<unordered_set<char>> boxes(SIZE);

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