#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vpii = vector<pair<int,int>>;
using vvi = vector<vector<int>>;

bool isSafe(vvi &grid, int x1, int y1, int x0, int y0, int n){
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || grid[x1][y1] != grid[x0][y0] + 1) {
        return false;
    }
    return true;
}
bool solve(vvi &grid, vpii &moves, int x0, int y0, int idx) {
    int x, y, n = grid.size();
    if (idx == (n * n) - 1) {
        return true;
    }
    for (auto move: moves) {
        int x1 = x0 + move.first;
        int y1 = y0 + move.second;
        if (isSafe(grid, x1, y1, x0, y0, n)) {
            grid[x0][y0] = -1;
            return(solve(grid, moves, x1, y1, idx + 1));
        }
    }
    return false;
}

int main() {
    vvi grid = {
        { 0, 11, 16,  5, 20},
        {17,  4, 19, 10, 15},
        {12,  1,  8, 21,  6},
        { 3, 18, 23, 14,  9},
        {24, 13,  2,  7, 22}};
    vpii moves = {
        {2, 1}, {-2, 1}, {2, -1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    cout << solve(grid, moves, 0, 0, 0);
    return 0;
}