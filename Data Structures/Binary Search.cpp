#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

void binarySearch(vector<int> arr, int len, int find) {
    int start = 0;
    int end = len - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == find) {
            cout << "found" << endl;
            return;
        }
        else if (arr[mid] < find)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << "not found" << endl;
}

int main() {
    int len;
    cin >> len;
    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); // USING QUICK SORT STL
    int find;
    cin >> find;
    binarySearch(arr, len, find);
    return 0;
}
