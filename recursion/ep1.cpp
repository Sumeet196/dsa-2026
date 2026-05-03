#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int sumOfnNumbers(int n) {
    if (n == 0) return 0;
    return n + sumOfnNumbers(n - 1);
}

int fibonaaci(int n) {
    if (n == 0 || n == 1) return n;
    return fibonaaci(n - 1) + fibonaaci(n - 2);
}

bool isSorted(vi &arr, int n) {
    if (n == 0 || n == 1) return true;
    return (arr[n-1] > arr[n-2] && isSorted(arr, n-1));
}

int recBinSearch(vi &arr, int target, int start, int end) {
    if (start <= end){ 
        int mid = start + (end - start) / 2;

        if(arr[mid] == target) return mid;
        else if (arr[mid] > target) return recBinSearch(arr, target, start, mid - 1);
        else return recBinSearch(arr, target, mid + 1, end);
    }
    return -1;
}

int search(vi &arr, int target) {
    return recBinSearch(arr, target, 0, arr.size() - 1);
}

void addSubsets(int idx, vi &arr, vvi &ans, vi &current){
    ans.push_back(current);
    for (int i = idx; i < arr.size(); i++){
        if(i > idx && arr[i] == arr[i-1]) continue;

        current.push_back(arr[i]);
        addSubsets(i+1, arr, ans, current);
        current.pop_back(); 
    }
}

int main() {
    // cout << factorial(20) << endl;
    // cout << sumOfnNumbers(5) << endl; 
    // cout << fibonaaci(4) << endl;
    // vi a = {1, 2, 5, 4};
    // cout << isSorted(a, 4) << endl;
    vi arr = {1, 2, 2};
    sort(arr.begin(), arr.end());
    vvi ans;
    vi current;
    addSubsets(0, arr, ans, current);
    for (auto &subset : ans) {
        cout << "{";
        for (auto &x : subset) {
            cout << x << ", ";
        }
        cout << "}" << endl;
    }
    return 0;
}