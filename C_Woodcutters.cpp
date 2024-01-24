#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<pair<long long, long long> > v(n);
    for (long long i = 0; i < n; i++)
    {
        long long x, h;
        cin >> x >> h;
        v[i].first = x;
        v[i].second = h;
    } // taking input

    long long treesCut = 2;
    for (long long i = 1; i < n - 1; i++)
    {
        if (v[i].first - v[i].second > v[i - 1].first)
        {
            treesCut++;
        } // making the tree fall to its left
        else if (v[i].first + v[i].second < v[i + 1].first)
        {
            v[i].first += v[i].second; // inc x coordinate by its height
            treesCut++;
        } // making the tree fall to right side
    }
    cout << treesCut << endl;

    return 0;
}