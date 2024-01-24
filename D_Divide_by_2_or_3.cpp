#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd calculation code

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //taking input

    int gcdValue = a[0]; // intial value
    for (int i = 1; i < n; i++)
        gcdValue = gcd(gcdValue, a[i]);
    // finding gcd of all the numbers in the array

    for (int i = 0; i < n; i++)
        a[i] /= gcdValue;
    // removing that gcd value from its factors , ie. divide all numbers with gcd

    int flag = true;

    int operations = 0; // operation count

    for (int i = 0; i < n; i++)
    {
        while (a[i] % 2 == 0)
        {
            operations++;
            a[i] /= 2;
        } // divide with 2 till possible
        while (a[i] % 3 == 0)
        {
            operations++;
            a[i] /= 3;
        } // divide with 3 till possible
        if (a[i] != 1)
        {
            flag = false;
            break;
        } // if after removing gcd, all 2s,
        // and all 3s, still the number is not 1 means answer is -1
    }

    if (flag)
        cout << operations << endl;
    else
        cout << -1 << endl; 

    return 0;
}