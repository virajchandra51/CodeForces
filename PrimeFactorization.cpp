#include <bits/stdc++.h>
using namespace std;

// trial division method
int main()
{
    long long n;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1)
        cout << n << " ";
    cout << endl;
    return 0;
}
// lowerbound - TC - log2(n) - when number is composite
// upperbound - TC - sqrt(n) - when number is prime

// TC - O(sqrt(n))

