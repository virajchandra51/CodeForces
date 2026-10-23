#include <bits/stdc++.h>
using namespace std;

int main()
{
    // LCM of 1 to 60 crosses 10^18 easily
    // long long a = 1;
    // for (long long i = 2; i <= 60; i++)
    // {
    //     a = lcm(a, i);
    // }
    // cout << a << endl;

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        int i = 1;
        while (n % i == 0) // O(60)
            i++;
        cout << i - 1 << endl;
    }
    return 0;
}

// Time Complexity: O(60) ~ O(log2(n))
// Space Complexity: O(1)