#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, c, d;
        cin >> n >> c >> d;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end()); // nlogn

        set<long long> s;        // to check for duplicates
        long long duplicate = 0; // to store duplicates count
        // uptil the ith index how many duplicate numbers exists

        long long minCost = c * n + d;
        // initial minCost where I remove everything and add 1 only

        for (int i = 0; i < n; i++) // n
        {
            if (s.find(a[i]) == s.end()) // logn
                s.insert(a[i]); // logn
            else
                duplicate++;

            // simple duplicate check

            long long cost = 0;

            cost += (duplicate * c);
            // removing the duplicate elements which occur till the ith index

            // if at ith index there is a requirement for insertion of some elements
            // which were not there, meaning a[i] - elements after removal of duplicates
            // is still positive, so add those

            if ((a[i]) - ((i + 1) - duplicate) > 0)
                cost += (((a[i]) - (i + 1 - duplicate)) * d);

            cost += ((n - i - 1) * c);

            // removing all the elements after this ith index
            minCost = min(minCost, cost);
        } // nlogn
        cout << minCost << endl;
    }
    return 0;
}

// TC - O(nlogn)
// SC - O(n)