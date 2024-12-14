#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long start, jumps;
        cin >> start >> jumps;

        if (jumps % 4 == 1)
            jumps = -jumps;
        else if (jumps % 4 == 2)
            jumps = 1;
        else if (jumps % 4 == 3)
            jumps = jumps + 1;
        else if (jumps % 4 == 0)
            jumps = 0;

        if (start % 2 == 0)
            start = start + jumps;
        else
            start = start - jumps;

        cout << start << endl;
    }
    return 0;
}