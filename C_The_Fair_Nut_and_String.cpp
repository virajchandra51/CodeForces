#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main()
{
    // taking input
    string s;
    cin >> s;

    // reducing the string to remove all letters beside a and b

    string reducedString = "";
    for (auto it : s)
        if (it == 'a' || it == 'b')
            reducedString += it;

    long long countOfA = 0; // storing count of a in each segment of A's
    long long answer = 1;

    // modulo multiplication
    // (a*b)%mod = ((a%mod)*(b%mod))%mod

    for (auto it : reducedString)
    {
        if (it == 'a')
            countOfA++;
        else
        {
            if (countOfA > 0)
                answer = ((answer % mod) * ((countOfA + 1) % mod)) % mod;
            countOfA = 0;
        }
    }
    if (countOfA > 0)
        answer = ((answer % mod) * ((countOfA + 1) % mod)) % mod;

    answer--;
    cout << answer << endl;

    return 0;
}