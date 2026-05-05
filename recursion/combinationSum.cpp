#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void combSum(vi &arr, int target, int start, vvi &ans, vi &current){
    if (target == 0) {
        ans.push_back(current);
        return;
    }
    
    for (int i = start; i < arr.size(); i++) {
        if (arr[i] > target) break;

        current.push_back(arr[i]);
        combSum(arr, target - arr[i], i, ans, current);
        current.pop_back();
    }
}

vvi solve(vi &arr, int target) {
    vvi ans;
    vi current;

    sort(arr.begin(), arr.end());

    combSum(arr, target, 0, ans, current);
    return ans;
}

int main() {
    vi arr = {2, 3, 5};
    int target = 8;
    vvi ans = solve(arr, target);
    for (auto i: ans) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}