#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    for (long long i = l; i <= r; i += 2) // (r-l)
        cout << i << " " << i + 1 << endl;
    return 0;
}

// tc - O(r-l)
// sc - O(1)