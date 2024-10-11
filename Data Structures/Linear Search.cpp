#include <iostream>
using namespace std;
#define endl '\n'

void linearSearch(int arr[], int len, int search) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == search) {
            // ! this condition only if all the values in an array are distinct.
            cout << search << " found at position " << i + 1 << endl;
            return;
        }
        /*
        int c = 0;
        if (arr[i] == search) {
             // * this condition if there are duplicates in an array.
             c++;
             cout << search << " found at position " << i + 1 ", ";
        }
        cout << endl;
        if (c == 0)
            cout << "Not Found" << endl;
        */
    }
    cout << "Not Found" << endl;
}
int main() {
    int len, search;
    cout << "Enter The Length of the Array: ";
    cin >> len;
    int arr[len];
    cout << "Enter The Array: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    cout << "Enter a value to search: ";
    cin >> search;
    linearSearch(arr, len, search);
    return 0;
}
