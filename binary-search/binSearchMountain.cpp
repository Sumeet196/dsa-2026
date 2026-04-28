#include <iostream>
#include <vector>
using namespace std;

int mountainPeak(vector <int> v) {
    int start = 0, end = v.size() - 1;
    int mid = start + (end - start) / 2;

    while(start <= end) {
        if (v[mid] > v[mid+1] & v[mid] > v[mid-1]){
            return mid;
        } 
        else if (v[mid] > v[mid+1] & v[mid] < v[mid-1]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return mid; 
}

int main(){
    vector <int> v = {1, 3, 4, 5, 3, 2};
    cout << mountainPeak(v) << endl;
    return 0;
}