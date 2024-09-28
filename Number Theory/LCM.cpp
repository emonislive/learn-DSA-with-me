// LCM (Least Common Multiple)
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int mod;
    while (b > 0) {
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

void lcm(int a, int b) {
    int GCD = gcd(a, b);
    int LCM = ((a / GCD) * b);
    printf("Least Common Multiple LCM(%d,%d): %d\n", a, b, LCM);
}

int main() {
    int a, b;

    cout << "Enter Two Numbers: ";
    cin >> a >> b;

    lcm(a, b);
    return 0;
}
