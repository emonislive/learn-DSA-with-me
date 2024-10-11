#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

// ! print method for dynamic 2D array
void printDynamicArray(vector<vector<int>> v, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
// ! print method for 1D dynamic array
void print1DDynamicArray(vector<int> v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}

// ! print method for 2D array
void print2DArray(int** arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// ! print method for 1D array
void print1DArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

// ! user input method for dynamic 2D array
void dynamic2DArray(int n) {
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({});        // * creating new row
        for (int j = 0; j < n; j++) {
            int in;
            cin >> in;
            v[i].push_back(in); // * Directly add the element to the current row
        }
    }
    printDynamicArray(v, n);
}

// ! user input method for dynamic 1D array
void dynamicArray(int n) {
    vector<int> v(n);
    int in;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    print1DDynamicArray(v, n);
}

// ! user input method for 2D array
void twoDArray(int n) {
    int** arr = new int* [n];       // * Allocate memory for the 2D array
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];        // * Allocate memory for each row
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    print2DArray(arr, n);

    // * Free up Memory from the heap
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

// ! user input method for 1D array
void oneDArray(int n) {
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    int n = 3;

    oneDArray(n);
    twoDArray(n);
    dynamicArray(n);
    dynamic2DArray(n);

    return 0;
}
