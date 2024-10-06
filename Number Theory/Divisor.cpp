#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'

/*
    for ex. n = 10, sqrt(10) = 3. loop will me with in 1..to..3, & divisors of 10 = 1, 2, 5, 10
    so after reducting the loop length, we will get this ans 1, 2 from the loop but 5, 10 is missing
    in that case, if (i != n / i) condition comes in. so , if i is divisible then (n/i) is also divisible
    ex. n = 10, i = 1, (10 / 1) = 10, i = 2, (10 / 2) = 5, now we can add the missing 5, 10.
    != is used because for ex. The divisors of 36 are: 1, 2, 3, 4, 6, 9, 12, 18, 36.
    now when i = 6, if (n % i == 0) this condition will be true, so c will increase by 1
    then again it will check if (i != n / i) this condition (36/6) = 6, so again the condition will be true
    so to counter the duplicates the != is added.
*/


void solve(int n)
{
    int c = 0;
    for (int i = 1; i <= sqrt(n); i++) 
    {
        if (n % i == 0) 
        {
            c++;
            if (i != n / i)
                c++;
        }
    }
    /* // this is the brute force method
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            c++;
        //  cout << i << " ";
        }
    }
    */
    /*
    // This is the most efficient method
    vector<ll> v(1000001, 0);
    for (ll i = 1; i < 1000001; i++)
    {
        for (ll j = i; j < 1000001; j += i)
        {
            v[j]++;
        }
    }
    cout << v[n] << endl;
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
