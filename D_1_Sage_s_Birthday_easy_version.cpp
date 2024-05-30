#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long> b(n);
    int i = 0;
    int j = n / 2;
    int k = 0;
    while (j < n)
    {
        b[k] = a[j];
        j++;
        k++;
        b[k] = a[i];
        i++;
        k++;
    }
    long long c = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && i < n - 1 && b[i] < b[i + 1] && b[i] < b[i - 1])
        {
            c++;
        }
    }
    cout << c << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}