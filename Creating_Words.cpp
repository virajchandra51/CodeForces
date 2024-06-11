#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b; 
        cin >> a >> b; // taking input of two strings
        swap(a[0], b[0]);
        cout << a << " " << b << endl;
    }
    return 0;
}

// TC - O(1)
// SC _ O(1)