#include <iostream>
using namespace std;
#define endl '\n'

void rec(int i, int n)
{

    if (i > n) // ! Base Case
    {
        return;
    }

    rec(i + 1, n);     // ! Recursion
    cout << i << endl; // ! Executes During Unwinding
}

int main()
{
    int n = 5;
    rec(1, n);
    return 0;
}

/*
 ? Unwinding in recursion refers to the process of returning back through the recursive calls after reaching the base case.
 */

/*
 *
 * Function Call	Action	            State of Call Stack
 * rec(1, 5)	    Call rec(2, 5)	    [rec(1, 5)]
 * rec(2, 5)	    Call rec(3, 5)	    [rec(1, 5), rec(2, 5)]
 * rec(3, 5)	    Call rec(4, 5)	    [rec(1, 5), rec(2, 5), rec(3, 5)]
 * rec(4, 5)	    Call rec(5, 5)	    [rec(1, 5), rec(2, 5), rec(3, 5), rec(4, 5)]
 * rec(5, 5)	    Call rec(6, 5)	    [rec(1, 5), rec(2, 5), rec(3, 5), rec(4, 5), rec(5, 5)]
 * rec(6, 5)	    Base case: Return	    (Start unwinding)
 *
 * Output: 5 4 3 2 1 (Reverse Print The Values)
 */
