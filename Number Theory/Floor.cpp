#include <iostream>
using namespace std;
#define endl '\n'
#define ll long long

void solve(ll a, ll b)
{
    ll floorValue = a / b;
    cout << floorValue << endl;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}
