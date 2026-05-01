#include <iostream>
#include <vector>
using namespace std;

int mountainPeak(vector<int> v)
{
    int start = 0, end = v.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] < v[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

int main()
{
    vector<int> v = {1, 3, 4, 5, 3, 2};
    cout << mountainPeak(v) << endl;
    return 0;
}