// GCD (Greatest Common Divisor) or HCF (Highest Common Factor)
#include <iostream>
using namespace std;

#define endl '\n'
void gcd() {
    int a, b, mod;
    cout << "Enter Two Numbers : ";
    cin >> a >> b;
    int tmp1 = a, tmp2 = b;
    while (b > 0) {
        mod = a % b;
        a = b;
        b = mod;
    }
    printf("Greatest Common Divisor GCD(%d,%d): %d\n", tmp1, tmp2, a);
}
int main() {
    gcd();
    return 0;
}
