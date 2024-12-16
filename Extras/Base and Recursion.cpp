#include <iostream>
using namespace std;
#define endl '\n'

void recursion(int n)
{
    int i = 0;
    if (n < 1) // ! Base Case [When to Stop]
    {
        return;
    }
    cout << i + 1 << " ";
    recursion(n - 1); // ! Function calling itself(recursion)
}

int main()
{
    int n;
    cin >> n;
    recursion(n);
    return 0;
}
