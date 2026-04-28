#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

int splitArray(vi &nums, int k) {
    int start = *max_element(nums.begin(), nums.end());
    int end = 0; for (auto i: nums) end += i;
    int ans = INT_MAX;
    while (start <= end) {
        int count = 1, currSum = 0;
        int allowedSum = start + (end - start) / 2;
        for (auto ele: nums) {
            if (currSum + ele > allowedSum) {
                count++; currSum = ele;
            } else {
                currSum += ele;
            }
        }
        if (count > k) {
            start = allowedSum + 1;
        } else {
            ans = min(ans, allowedSum);
            end = allowedSum - 1;
        }
    }
    return ans;
}

int main() {
    vi nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << splitArray(nums, k) << endl;
    return 0;
}