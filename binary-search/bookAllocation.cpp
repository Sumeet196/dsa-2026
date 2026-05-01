#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

bool isAllocationPossible(vi &pages, int numOfPeople, int maxPagesAllowed) {
    int requiredStudents = 1;
    int currentPages = 0;
    for (int page: pages) {
        if(currentPages + page > maxPagesAllowed) {
            requiredStudents++;
            currentPages = page;
        } else {
            currentPages += page;
        }
    }
    return (numOfPeople >= requiredStudents);
}

int findPages(vi &nums, int k) {
    if (k > nums.size()) return -1;

    int start = *max_element(nums.begin(), nums.end());
    int end = 0; for (auto i: nums) end += i;

    int answer = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (isAllocationPossible(nums, k, mid)) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return answer;
}

int main() {
    vi nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << findPages(nums, k) << endl;
    return 0;
}