#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    long long a, b;
    for (long long i = 1; i * i <= x; i++) // sqrt x
    {
        if (x % i == 0 && i * (x / i) / __gcd(i, x / i) == x) // log2(min(i,x/i))
        {
            a = i;
            b = x / i;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}

// tc - O(sqrt(x)*log2(min(i,x/i))) = O(10^6*20) = O(2*10^7)
// sc - O(1)
