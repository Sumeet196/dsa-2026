#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void combSum(vi &arr, int target, int idx, vvi &ans, vi &current){
    if (target < 0) return;
    if (target == 0) {
        ans.push_back(current);
        return;
    }
    if (idx == arr.size()) return;
    current.push_back(arr[idx]);
    combSum(arr, target - arr[idx], idx, ans, current);
    current.pop_back();
    combSum(arr, target, idx + 1, ans, current);
}

/*
cb([],0,8)
    curr[3]
    cb([3],0,5)
        curr[3,3]
        cb([3,3],0,2)
            curr[3,3,3]
            cb([3,3,3],0,-1)
            curr[3,3]
            cb([3,3],1,2)
                curr[3,3,5]
                cb([3,3,5],1,-3)
                curr[3,3]
                cb([3,3],2,2)
        curr[3]
        cb([3],1,5)
            curr[3,5]
            cb([3,5],1,0)
                ans.push([3,5])

*/

vvi solve(vi &arr, int target) {
    vvi ans;
    vi current;
    int idx = 0;
    combSum(arr, target, idx, ans, current);
    return ans;
}

int main() {
    vi arr = {2, 3, 5};
    int target = 8;
    vvi ans;
    ans = solve(arr, target);
    for (auto i: ans) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}