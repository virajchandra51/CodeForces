#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (n / i != i)
                cout << n / i << " ";
        }
    }
    cout << endl;
    return 0;
}