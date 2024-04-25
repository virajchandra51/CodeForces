#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) // outer loop
    {
        for (int j = 1; j <= i; j++) // inner loop
        {
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}