#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

bool isValid(vi &stalls, int cows, int minDistance) {
    int lastPlacedIndex = 0;
    int cowsPlaced = 1;
    int currentIndex = 1; 

    while (cowsPlaced < cows && currentIndex < stalls.size()) {
        if (stalls[currentIndex] - stalls[lastPlacedIndex] >= minDistance) {
            cowsPlaced++;
            lastPlacedIndex = currentIndex;
        }
        currentIndex++;
    }
    return (cowsPlaced==cows);
}

int aggressiveCows(vi &stalls, int cows) {
    int totalStalls = stalls.size();
    sort(stalls.begin(), stalls.end());

    int start = 1, end = stalls[totalStalls - 1] - stalls[0];
    int maxMinDistance = 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isValid(stalls, cows, mid)) {
            maxMinDistance = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return maxMinDistance;
}

int main() {
    vi stalls = {6, 1, 9, 3, 8};
    // 1 3 6 8 9
    int cows = 3;
    cout << aggressiveCows(stalls, cows) << endl;
    return 0;
}