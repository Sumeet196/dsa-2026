#include <iostream>
#include <vector>
#include <string>
using namespace std;

int pivot(vector <int> v) {
    int start = 0, end = v.size() - 1;
    if (v[start] < v[end]) return start;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (v[mid] >= v[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

int pivot_search(vector <int> v, int target) {
    int start = 0, end = v.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == target) return mid;
        if (v[start] <= v[mid]) {
            if (v[start] <= target && target <= v[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (v[mid] <= target && target <= v[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector <int> v = {7, 9, 11, 12, 3, 4};
    int target = 9;
    cout << pivot(v) << endl;
    cout << pivot_search(v, target) << endl;
    return 0;
}