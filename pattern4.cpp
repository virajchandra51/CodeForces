#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    // cout<<n<<endl;
    for (int i = 1; i <= n; i++) // outer loop
    {
        int hashes = n-i;
        int printing = i;
        for(int j=1;j<=hashes;j++) cout<<" ";
        for(int j=1;j<=printing;j++) cout<<"* ";
        cout<<endl;
    }
    return 0;
}