#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

double median(vi &arr1, vi &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;

    if (n1 > n2) {
        return median(arr2, arr1);
    }

    int low = 0;
    int high = n1;

    while (low <= high) {
        int m1 = (low + high) / 2;
        int m2 = (n + 1) / 2 - m1;

        int l1 = (m1 == 0) ? INT_MIN : arr1[m1-1];
        int l2 = (m2 == 0) ? INT_MIN : arr2[m2-1];
        int r1 = (m1 == n1) ? INT_MAX : arr1[m1];
        int r2 = (m2 == n2) ? INT_MAX : arr2[m2];

        if (l1 > r2) high = m1 - 1;
        else if (l2 > r1) low = m1 + 1;
        else {
            if (n % 2 == 0) {
                return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
            } else {
                return (double)max(l1, l2);
            }
        }
    }
    return -1;
}

int main() {
    vi arr1 = {1, 3, 7, 12};
    vi arr2 = {2, 3, 6, 15};
    cout << median(arr1, arr2) << endl;
    return 0;
}