#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m; // taking input

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    // base case

    vector<long long> fact(n + 1, 0);
    fact[0] = 1;
    fact[1] = 1;

    // calclating factorials with modulo multiplication

    for (int i = 2; i <= n; i++)
    {
        fact[i] = ((fact[i - 1] % m) * (i % m)) % m;
    }

    long long totalSumOfSegments = 0;

    // using modulo multiplication and modulo addition

    // I define D = r-l, which means the difference I'm trying to maintain

    // initially D starts from 0

    for (int i = n; i >= 1; i--)
    {
        long long framedSegments = ((i % m));
        // how many options do I have to keep at a given [l,r]

        framedSegments = ((framedSegments % m) * (fact[n - i + 1] % m)) % m;
        // multiplication which denotes the permutation of the chosen options in between l and r indexes

        framedSegments = ((framedSegments % m) * (fact[i - 1] % m)) % m;
        // after keeping the options, how many ways can I fill the left over places

        framedSegments = ((framedSegments % m) * (i % m)) % m;
        // how many [l,r] pairs exist such that the Difference of r-l remains D ?

        totalSumOfSegments = ((totalSumOfSegments % m) + (framedSegments % m)) % m;
        // adding that value to totalSumOfSegments
    }

    cout << totalSumOfSegments << endl;

    return 0;
}

// time complexity - O(n)
// space complexity - O(n)