#include <iostream>
using namespace std;
#define endl '\n'

void printSortedArray(int arr[], int len) {
    cout << "Sorted Array in Ascending Order: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Sorted Array in Descending Order: ";
    for (int i = len - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/*
    * The function now takes a and b as reference parameters (int&).
    * This means any modifications made to a and b within the function
    * will affect the original variables passed to it
*/
void swapValue(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
/*
    * why j = i+1 ? why not j = 0, because after sorting in one iteration we do not need to go
    * through from the starting point over again for the next iteration because
    * the sorted elements are already smallest than the leftover unsorted values
    * so that avoids going through unnecessary traversal and makes the sorting fast.
    * for j = 0, then total loop will occur   = len * len,           let len = 10, -> 10 * 10 = 100 times
    * for j = i+1, then total loop will occur = len * (len - 1) / 2, let len = 10, -> 10 * (10-1) / 2 = 45 times
*/
void selectionSort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len;j++) {
            if (arr[i] < arr[j])
                swapValue(arr[i], arr[j]);
        }
    }
    printSortedArray(arr, len);
}

int main() {
    int len;
    cout << "Enter The Length of the Array: ";
    cin >> len;
    int arr[len];
    cout << "Enter The Array: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, len);
}
