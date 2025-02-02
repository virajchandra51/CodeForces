#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;
        long long sticks_needed_for_coal = k * y;
        long long sticks_needed = k;
        long long trades = sticks_needed_for_coal + sticks_needed - 1;
        trades += (x - 2);
        trades /= (x - 1);
        trades += k;
        cout << trades << endl;
    }
}