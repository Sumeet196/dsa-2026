#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findOcc(vector <int> vi, int target, bool isFirst) {
    int n = vi.size();
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    int ans = -1;

    while (start <= end) {
        if (vi[mid] == target) {
            ans = mid;
            if (isFirst) end = mid - 1;
            else start = mid + 1;
        } else if (vi[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
        }
    return ans;
}

int main() {
    vector <int> vi = {1, 2, 3, 3, 3, 5};
    cout << findOcc(vi, 3, 0);
    return 0;
}