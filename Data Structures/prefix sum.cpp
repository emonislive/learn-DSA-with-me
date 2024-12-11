#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long

void solve(int size)
{
    vector<ll> arr(size), prefixSum(size);
    ll sum = 0;
    cout << "Insert Array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        prefixSum[i] = sum;
    }
    cout << "Prefix Sum: ";
    for (auto i : prefixSum)
    {
        cout << i << " ";
    }
}

int main()
{
    int size;
    cout << "Array Size: ";
    cin >> size;
    solve(size);
    return 0;
}
