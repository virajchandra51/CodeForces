#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) // outer loop
    {
        for (int j = 1; j <= m; j++) // inner loop
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}