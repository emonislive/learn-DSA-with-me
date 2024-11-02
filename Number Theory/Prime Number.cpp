#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'

int primeOrNot(int num)
{
    if (num < 2)
        return 0;

    for (int i = 2; i <= sqrt(num); i++) // Trial Division Algorithm
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int num;
    cin >> num;
    
    if (primeOrNot(num))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
  
    return 0;
}
