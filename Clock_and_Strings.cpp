#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b)
            swap(a, b);
        unordered_set<long long> s1;
        for (long long i = a + 1; i < b; i++)
            s1.insert(i);
        unordered_set<long long> s2;
        for (long long i = 1; i <= 12; i++)
        {
            if (s1.find(i) == s1.end() && i != a && i != b)
                s2.insert(i);
        }
        if ((s1.count(c) && s2.count(d)) || (s1.count(d) && s2.count(c)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// tc ~ O(1)
// sc ~ O(1)