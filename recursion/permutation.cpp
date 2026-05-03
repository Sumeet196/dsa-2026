#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;

void findPerms(string &s, vs &ans, int idx, int n) {
    if (idx == n) {
        ans.push_back(s);
    }
    for (int i = idx; i < n; i++) {
        swap(s[i], s[idx]);
        findPerms(s, ans, idx + 1, n);
        swap(s[i], s[idx]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "ABCD";
    int n = s.size();
    vs ans;
    findPerms(s, ans, 0, n);
    for (auto a : ans) {
        cout << a << endl;
    }
    return 0;
}