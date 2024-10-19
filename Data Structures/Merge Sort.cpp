#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

void print(vector<int> arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>& arr, int start, int mid, int end) {
    int s1ze = mid - start + 1;
    int s2ze = end - mid;
    vector<int> leftArr(s1ze), rightArr(s2ze);
    for (int i = 0; i < s1ze; i++) {
        leftArr[i] = arr[start + i];
    }
    for (int i = 0; i < s2ze; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i < s1ze && j < s2ze) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < s1ze) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < s2ze) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int len;
    cin >> len;
    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, len - 1);
    print(arr, len);
    return 0;
}
