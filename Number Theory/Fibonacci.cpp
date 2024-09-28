#include <iostream>
using namespace std;
#define endl '\n'

void fibonacci(int a) {
    int first = 0, second = 1, next;
    cout << "Fibonacci Sequence: ";
    if (a == 1) {
        cout << first << endl;
        return;
    }
    else if (a == 2) {
        cout << first << " " << second << endl;
        return;
    }
    cout << first << " " << second << " ";
    for (int i = 2; i < a; i++) {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
}

int main() {
    int a;

    cout << "Enter The Number of Terms: ";
    cin >> a;

    fibonacci(a);
    return 0;
}
