#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end()); //nlogn

    vector<int> range(n,0);
    for (int i = 0; i < q; i++) // q
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        range[L]++; //1
        if (R + 1 < n)
            range[R + 1]--; //1
    } //q

    for (int i = 1; i < n; i++) //n
        range[i] += range[i - 1];

    // for(auto it:range) cout<<it<<" ";
    // cout<<endl;

    sort(range.begin(), range.end()); // nlogn

    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer += 1ll * range[i] * a[i];
    }
    cout << answer << endl;
    return 0;
}

// tc - O(nlogn+q+n) ~ 10^5-10^6
// sc - O(n)
