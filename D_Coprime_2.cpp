#include <bits/stdc++.h>
using namespace std;

vector<long long> primeFactors(long long x)
{
    vector<long long> res;
    for (long long i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            res.push_back(i);
        }
    }
    if (x != 1)
    {
        res.push_back(x);
    }
    return res;
}

// basic code to find prime factors of a number in O(sqrt(n)) complexity

int main()
{

    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // taking input

    vector<long long> feasibleK(100005, 1);

    for (int i = 0; i < n; i++)
    {
        vector<long long> primeF = primeFactors(a[i]);
        for (auto f : primeF)
        {
            if (feasibleK[f]==1)
            {
                for (int j = f; j <= m; j += f)
                    feasibleK[j] = 0;
            }
        }
    }

    int countOfFeasibleK = 0;
    for (int i = 1; i <= m; i++)
        countOfFeasibleK += feasibleK[i];

    cout << countOfFeasibleK << endl;

    for (int i = 1; i <= m; i++)
    {
        if (feasibleK[i])
            cout << i << endl;
    }

    return 0;
}

// time complexity - O(n * sqrt(max(arr)))
// space complexity - O(n)