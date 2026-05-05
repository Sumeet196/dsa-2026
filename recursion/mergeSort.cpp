#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// --- ORIGINAL UNOPTIMIZED VERSION ---
// Space Complexity: O(N log N) peak memory due to allocating new vectors 
// at every level of the recursion tree.
// Time Complexity: O(N log N), but with a massive constant factor because 
// dynamically allocating vectors (vi left, vi right, vi merged) is slow.
/*
vi merge(vi arr1, vi arr2) {
    int num1 = arr1.size(), num2 = arr2.size();
    int p1 = 0, p2 = 0;
    vi merged;
    while (p1 < num1 || p2 < num2) {
        if ((p2 == num2) || ((p1 < num1) && (arr1[p1] < arr2[p2]))) {
            merged.push_back(arr1[p1]);
            p1++;
        } else {
            merged.push_back(arr2[p2]);
            p2++;
        }
    }
    return merged;
}

vi mergeSort(vi &nums) {
    if (nums.size() == 0 || nums.size() == 1) {
        return nums;
    }
    int mid = nums.size() / 2;
    vi left(nums.begin(), nums.begin() + mid);
    vi right(nums.begin() + mid, nums.end());
    return merge(mergeSort(left), mergeSort(right));
}
*/

// --- OPTIMIZED VERSION ---

// TIME OPTIMIZATION: We no longer return a new vector. We merge directly 
// into the pre-allocated 'temp' array. This eliminates the O(N) memory 
// allocation overhead that used to happen during every single merge.

void merge(vi &nums, int left, int mid, int right, vi &temp) {
    int p1 = left, p2 = mid + 1, idx = left;

    // Time: O(N) to iterate through the subarrays. 
    // Since this runs at every level of the log N recursion tree, 
    // the overall time complexity of the algorithm remains O(N log N).
    while (p1 <= mid && p2 <= right) {
        if (nums[p1] < nums[p2]) {
            temp[idx++] = nums[p1++];
        } else {
            temp[idx++] = nums[p2++];
        }
    }
    while (p1 <= mid) temp[idx++] = nums[p1++];
    while (p2 <= right) temp[idx++] = nums[p2++];

    // Copy the merged elements back to the original array.
    for(int i = left; i <= right; i++) {
        nums[i] = temp[i];
    }
}

// SPACE/TIME OPTIMIZATION: Instead of physically slicing the array 
// (which takes O(N) time and space per slice), we just pass indices 
// (left, mid, right) to represent the boundaries.

void mergeSortHelper(vi &nums, int left, int right, vi &temp) {
    // Space: The call stack goes log N levels deep, taking O(log N) space.
    if (left >= right) return; 

    int mid = left + (right - left) / 2;

    mergeSortHelper(nums, left, mid, temp);
    mergeSortHelper(nums, mid + 1, right, temp);

    merge(nums, left, mid, right, temp);
}

void mergeSort(vi &nums) {
    if (nums.empty()) return;

    // SPACE OPTIMIZATION: We allocate memory exactly ONCE. 
    // This takes strict O(N) space. Because O(N) dominates the O(log N) 
    // stack space from the recursion, the final Space Complexity is O(N).
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