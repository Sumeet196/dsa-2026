#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void merge(vi &arr, vi &temp, int left, int mid, int right) {
    int ptr1 = left, ptr2 = mid + 1, idx = left;

    while (ptr1 <= mid && ptr2 <= right) {
        if (arr[ptr1] <= arr[ptr2]) {
            temp[idx++] = arr[ptr1++];
        } else {
            temp[idx++] = arr[ptr2++];
        }
    }
    while (ptr1 <= mid) temp[idx++] = arr[ptr1++];
    while (ptr2 <= right) temp[idx++] = arr[ptr2++];

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }  
}

void msHelper(vi &arr, vi &temp, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    msHelper(arr, temp, left, mid);
    msHelper(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

void mergeSort(vi &arr) {
    if (arr.empty()) return;
    vi temp(arr.size());
    msHelper(arr, temp, 0, arr.size() - 1);
}

int main() {
    vi arr = {1, 9, 23, 2, 7, 12, 25};
    mergeSort(arr);
    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}