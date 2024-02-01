#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    n *= 2;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // taking input

    sort(v.begin(), v.end()); // sort the array

    long long firstN = 0; // sum of first N ele 
    long long lastN = 0; // sum of last N ele

    for (int i = 0; i < n / 2; i++)
        firstN += v[i];
    // calculate sum of first N ele
    
    for (int i = n / 2; i < n; i++)
        lastN += v[i];
    // calculate sum of last N ele

    if (firstN != lastN) // if not equal print array
    {
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl; // else -1

    return 0;
}

// TC - O(nlogn + n) ~ O(nlogn)
// SC - O(1)