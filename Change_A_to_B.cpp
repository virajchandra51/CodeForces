#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, k;
        cin >> a >> b >> k;
        long long op = 0;
        while (a != b)
        {
            if (b % k != 0)
            {
                long long f = b / k;
                long long nearestMultiple = f * k;
                op += (b - nearestMultiple);
                b = nearestMultiple;
            }
            else if (b / k >= a)
            {
                b /= k;
                op++;
            }
            else
            {
                op += (b - a);
                break;
            }
        }
        cout << op << endl;
        // tc - O(log (base K) (B))
        // sc - O(1)
    }
    return 0;
}