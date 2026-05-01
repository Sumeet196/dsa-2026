#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

bool isAllowed(vi &arr, int numOfPainters, int mid) {
    int paintersAllocated = 1;
    int paintSum = 0;
    for(int a: arr) {
        if (paintSum + a <= mid) {
            paintSum += a;
        } else {
            paintersAllocated++;
            paintSum = a;
        }
    }
    return (paintersAllocated <= numOfPainters);
}

int painters(vi &arr, int k) {
    int maxVal = arr[0];
    int totalSum = 0;
    for (int a: arr){
        maxVal = max(a, maxVal);
        totalSum += a;
    }
    int answer = -1;
    int start = maxVal, end = totalSum;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if(isAllowed(arr, k, mid)){
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return answer;
}

int main() {
    vi arr = {10, 30, 20, 40};
    int k = 2;
    cout << painters(arr, k) << endl;
    return 0;
}