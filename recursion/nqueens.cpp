#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

bool addQueens(vs &board, vvs &ans, int row, int n, vi &cols, vi &diag1, vi &diag2) {
    if (row == n){
        ans.push_back(board);
        return true;
    }
    for(int col = 0; col < n; col++) {
        if(cols[col] == 1 || diag1[row + col] == 1 || diag2[row - col + n] == 1) continue;
        
        board[row][col] = 'Q';
        cols[col] = diag1[row + col] = diag2[row - col + n] = 1;
        
        if(addQueens(board, ans, row + 1, n, cols, diag1, diag2)) {
            return true;
        }

        board[row][col] = '.';
        cols[col] = diag1[row + col] = diag2[row - col + n] = 0;
    }
    return false;
}

vvs solvedQueens(int n) {
    string rowChar;
    for(int i = 0; i < n; i++) {
        rowChar.push_back('.');
    }
    vs board(n, rowChar);
    vi cols(n, 0), diag1(2*n, 0), diag2(2*n, 0);
    vvs ans;
    addQueens(board, ans, 0, n, cols, diag1, diag2);
    return ans;
}

int main() {
    int n = 4;
    vvs ans = solvedQueens(n);
    for (auto i: ans) {
        for (auto k: i) {
            cout << k;
        }
        cout << endl;
    }
    return 0;
}