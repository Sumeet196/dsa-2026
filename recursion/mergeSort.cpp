#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// vi merge(vi arr1, vi arr2) {
//     int num1 = arr1.size(), num2 = arr2.size();
//     int p1 = 0, p2 = 0;
//     vi merged;
//     while (p1 < num1 || p2 < num2) {
//         if ((p2 == num2) || ((p1 < num1) && (arr1[p1] < arr2[p2]))) {
//             merged.push_back(arr1[p1]);
//             p1++;
//         } else {
//             merged.push_back(arr2[p2]);
//             p2++;
//         }
//     }
//     return merged;
// }

// vi mergeSort(vi &nums) {
//     if (nums.size() == 0 || nums.size() == 1) {
//         return nums;
//     }
//     int mid = nums.size() / 2;
//     vi left(nums.begin(), nums.begin() + mid);
//     vi right(nums.begin() + mid, nums.end());
//     return merge(mergeSort(left), mergeSort(right));
// }

void merge(vi &nums, int left, int mid, int right, vi &temp) {
    int p1 = left, p2 = mid + 1, idx = left;
    while (p1 <= mid && p2 <= right) {
        if (nums[p1] < nums[p2]) {
            temp[idx++] = nums[p1++];
        } else {
            temp[idx++] = nums[p2++];
        }
    }
    while (p1 <= mid) temp[idx++] = nums[p1++];
    while (p2 <= right) temp[idx++] = nums[p2++];
    for(int i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}

void mergeSortHelper(vi &nums, int left, int right, vi &temp) {
    if (left >= right) return; 
    int mid = left + (right - left) / 2;

    mergeSortHelper(nums, left, mid, temp);
    mergeSortHelper(nums, mid + 1, right, temp);

    merge(nums, left, mid, right, temp);
}

void mergeSort(vi &nums) {
    if (nums.empty()) return;

    vi temp(nums.size());
    mergeSortHelper(nums, 0, nums.size() - 1, temp);
}

int main() {
    vi nums = {1, 5, 2, 4, 7, 3, 5, 9};
    mergeSort(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    return 0;
}