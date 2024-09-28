#include <iostream>
using namespace std;
#define endl '\n'
#define ul unsigned long long int
/*
Note: unsigned long long int has range of 0 to 18446744073709551615 bigger than long long int with range of −9223372036854775808 to 9223372036854775807 if we ignore the negative numbers of long long int
      ***Factorial is not defined for negative numbers.
      with this datatype we can only get max factorial of 20! which is 2432902008176640000
      if you want to print the factorial of beyond 20 then you have to take a different approach
*/
void factorial(ul a) {
    ul fact = 1;
    for (ul i = 1; i <= a; i++) {
        fact *= i;
    }
    cout << "Factorial of " << a << "! : " << fact << endl;
}

int main() {
    ul a;

    cout << "Enter The Number: ";
    cin >> a;

    factorial(a);
    return 0;
}
