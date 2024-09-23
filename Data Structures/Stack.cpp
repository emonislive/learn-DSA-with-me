#include <iostream>
#include <vector>
using namespace std;
// always remember stack follows the LIFO (Last In First Out) formula, the method used here.
// globally assigned dynamic array (vector for C++)
vector<int> v, popped;

void push(int in)
{
    v.push_back(in);
}
void pop()
{
    int removed = v[v.size() - 1];
    v.pop_back();
    // this is to show that the LIFO (last is first out pop system is reversed process compare to the pushing normal process).
    // storing the removed values in a new vector to show in which order the popping is conducted
    popped.push_back(removed);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // pushing / inputting values one at a time to the stack
    push(11);
    push(22);
    push(33);

    cout << "After pushing values to the stack: \n";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << '\n';

    // popping / deleting a values from the stack one at a time from the last element to first element.
    pop();
    pop();

    cout << "After popping the values we have left: \n";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << '\n';

    cout << "Elements deleted order in the stack: \n";
    for (auto i : popped)
    {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}
