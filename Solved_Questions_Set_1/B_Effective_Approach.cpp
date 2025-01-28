#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long m;
    cin >> m;
    vector<long long> queries(m);
    for (long long i = 0; i < m; i++)
        cin >> queries[i];

    vector<long long> comparisons(n);
    for (long long i = 0; i < n; i++)
        comparisons[a[i] - 1] = i + 1;
    long long left_comparisons = 0, right_comparisons = 0;
    for (long long i = 0; i < m; i++)
    {
        left_comparisons += comparisons[queries[i] - 1];
        right_comparisons += n - comparisons[queries[i] - 1] + 1;
    }
    cout << left_comparisons << " " << right_comparisons << endl;
    return 0;
}