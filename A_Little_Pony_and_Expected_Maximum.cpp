#include <bits/stdc++.h>
using namespace std;

int main()
{
    double m, n;
    cin >> m >> n;

    // taking input 

    double answer = m;
    for (double i = m - 1; i >= 1; i--)
    {
        double sub = pow(i / m, n); // O(logn)
        answer -= sub;
    }
    cout << setprecision(12) << answer << endl;
    return 0;
}

// time complexity = O(mlogn)
// spcae complexity = O(1)
