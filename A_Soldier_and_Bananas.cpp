#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long k, n, w;
    cin >> k >> n >> w;
    long dollars_needed = 0;

    for (long i = 1; i <= w; i++)
    {
        dollars_needed += i * k;
    }

    long money_short = dollars_needed - n;
    if (money_short > 0)
    {
        cout << money_short << "\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}