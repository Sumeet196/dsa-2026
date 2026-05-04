#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;

void mazeRunner(vvi &maze, vs &ans, string &path, int n, int row, int col) {
    if (row < 0 || col < 0 || row >= n || col >=n || maze[row][col] == 0) {
        return;
    }
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    maze[row][col] = 0;

    path.push_back('D');
    mazeRunner(maze, ans, path, n, row + 1, col);
    path.pop_back();

    path.push_back('U');
    mazeRunner(maze, ans, path, n, row - 1, col);
    path.pop_back();

    path.push_back('R');
    mazeRunner(maze, ans, path, n, row, col + 1);
    path.pop_back();

    path.push_back('L');
    mazeRunner(maze, ans, path, n, row, col - 1);
    path.pop_back();

    maze[row][col] = 1;
}

int main() {
    vvi maze = {
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {0, 0 ,1 ,1, 0},
        {1, 1, 1, 1, 1}
    };
    vs ans;
    string path = "";
    int n = maze.size();

    if(maze[0][0] == 1 && maze[n-1][n-1] == 1) {
        mazeRunner(maze, ans, path, n, 0, 0);
    }

    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}