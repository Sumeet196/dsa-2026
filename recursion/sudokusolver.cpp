#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;

#define fast ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool sudokuSolver(
    vvc &board, int bsize, int row, int col, vvi &row_used, 
    vvi &col_used, vvi &box_used
) {
    if (col == bsize) {
        row += 1;
        col = 0;
    }
    if (row == bsize) {
        return true;
    }
    char c = board[row][col];
    int box = (row / 3) * 3 + (col / 3);

    if (c != '.') {
        return sudokuSolver(board, bsize, row, col + 1, row_used, col_used, box_used);
    }

    for (int d = 0; d < bsize; d++) {
        if (row_used[row][d] || col_used[col][d] || box_used[box][d]) continue;
        
        board[row][col] = d + '1';
        row_used[row][d] = col_used[col][d] = box_used[box][d] = 1;

        if (sudokuSolver(board, bsize, row, col + 1, row_used, col_used, box_used)) {
            return true;
        }

        board[row][col] = '.';
        row_used[row][d] = col_used[col][d] = box_used[box][d] = 0;
    }
    return false;
}

int main() {
    fast;
    vvc board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    int n = 9;
    vvi row_used(9, vi(9, 0));
    vvi col_used(9, vi(9, 0));
    vvi box_used(9, vi(9, 0));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] != '.') {
                int d = board[r][c] - '1';
                int box = (r / 3) * 3 + (c / 3);
                row_used[r][d] = col_used[c][d] = box_used[box][d] = 1;
            }
        }
    }

    sudokuSolver(board, 9, 0, 0, row_used, col_used, box_used);
    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}