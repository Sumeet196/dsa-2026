#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solveSubsets(vi &arr, vvi &ans, int idx, vi &current){
    ans.push_back(current);
    for(int i = idx; i < arr.size(); i++) {
        if (i > idx && arr[i] == arr[i-1]) continue;
        current.push_back(arr[i]);
        solveSubsets(arr, ans, i + 1, current);
        current.pop_back();
    }
}

vvi subsets(vi &arr){
    vvi ans = {};
    vi current;
    solveSubsets(arr, ans, 0, current);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr = {1, 2, 3, 4};
    vvi ans = subsets(arr);
    cout << ans.size() << endl;
    for (auto i: ans) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
