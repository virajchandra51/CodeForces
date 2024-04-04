#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        // taking input

        long long a = x; // fix 'a' to x
        long long b = x;

        long long shiftParameter = (log2(x) + 1); // highest bit + 1
        b <<= shiftParameter;                     // shift b to right by that parameter
        b += x;                                   // add n to b now

        cout << a << " " << b << endl;
    }
    return 0;
}

// tc - O(log2(n))
// sc - O(1)



