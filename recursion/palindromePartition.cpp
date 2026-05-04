#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

bool isPalindrome(string s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s;
}

void palindromePartition(string str, vs &current, vvs &ans) {
    if (str.size() == 0) {
        ans.push_back(current);
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        string left = str.substr(0, i + 1);
        string right = str.substr(i + 1);
        if(isPalindrome(left)) {
            current.push_back(left);
            palindromePartition(right, current, ans);
            current.pop_back();
        }
    }
}

vvs solve(string str) {
    vvs ans;
    vs current;
    palindromePartition(str, current, ans);
    return ans;
}

int main() {
    string str = "aabacdcddca";
    vvs ans = solve(str);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}