#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

void printArray(vector<int> sortedArray, int n) {
    cout << "Sorted Array: ";
    for (int i : sortedArray) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> bubbleSort(vector<int> v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    return v;
}

int main() {
    int n;
    cout << "Enter Array Size: ";
    cin >> n;
    cout << "Enter The Array Elements: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> sortedArray = bubbleSort(v, n);
    printArray(sortedArray, n);
    return 0;
}
