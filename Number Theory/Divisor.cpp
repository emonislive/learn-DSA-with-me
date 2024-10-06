#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'

void solve(int n)
{
    int c = 0;
    // this is the efficient way to find the total divisor of a number
    for (int i = 1; i <= sqrt(n); i++) 
    {
        if (n % i == 0)
            c++;
    }
    /* this is the brute force method
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            c++;
        //  cout << i << " ";
        }
    }
    */
    cout << c << endl;
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}
