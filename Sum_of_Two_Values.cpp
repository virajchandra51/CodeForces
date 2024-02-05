#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // take input

    map<int, int> mp;
    int flag = 0;
    int i1 = -1;
    int i2 = -1;

    for (int i = 0; i < n; i++) // O(n)
    {
        if (mp.find(x - a[i]) != mp.end()) //O(logn)
        {
            i1 = i+1;
            i2 = mp[x - a[i]]+1;
            flag = 1;
            break;
        }
        mp[a[i]] = i; // O(logn)
    }

    if (flag)
        cout << i1 << " " << i2 << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}

// TC - O(nlogn)
// SC - O(n)