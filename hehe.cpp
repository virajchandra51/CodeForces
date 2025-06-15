#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        long long l = 1;
        for (long long i = 1; i <= 100; i++)
        {
            l = lcm(l, i);
        }
        cout << l << endl;
    }
}