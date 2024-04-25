#include <bits/stdc++.h>
using namespace std;

void f(int i, string curr, int n, vector<int> &arr)
{
    if (i == n)
    {
        if (!curr.empty())
            arr.push_back(stoi(curr));
        return;
    }
    curr += '1';
    f(i + 1, curr, n, arr);
    curr.pop_back();
    curr += '0';
    f(i + 1, curr, n, arr);
    curr.pop_back();
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> arr;
    f(0, "", n, arr);
    int a = stoi(s);
    arr.pop_back();
    // for (auto it : arr)
    //     cout << it << " ";
    // cout << endl;
    // cout<<arr.size() << endl;
    for (auto x : arr)
    {
        if (x == 1)
            continue;
        while (a % x == 0)
            a /= x;
    }
    if (a != 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main()
{

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}