#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> freq;
    for (long long i = 0; i < n; i++) // n
    {
        cin >> a[i];
        freq[a[i]]++; // logn
    }
    long long mex = 0;
    for (long long i = 0; i <= n; i++) // n
    {
        if (freq[i] == 0)
        {
            mex = i;
            break;
        }
        else if (freq[i] < 3)
        {
            cout << "-1 -1\n";
            return;
        }
    }

    long long l, r, sum = 0;
    vector<long long> f2(mex, 0);

    set<long long> st;
    for (long long i = 0; i < mex; i++) // n
        st.insert(i); // logn

    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
        st.erase(a[i]);
        if (st.empty())
        {
            l = i + 1;
            break;
        }
    }

    for (long long i = 0; i < mex; i++)
        st.insert(i);

    for (long long i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        st.erase(a[i]);
        if (st.empty())
        {
            r = i - 1;
            break;
        }
    }

    if (r < l)
    {
        cout << "-1 -1\n";
        return;
    }

    for (long long i = l; i <= r; i++)
    {
        sum -= a[i];
        if (a[i] < mex)
            f2[a[i]]++;
    }

    for (long long i = 0; i < mex; i++)
    {
        if (f2[i] == 0)
        {
            cout << "-1 -1\n";
            return;
        }
    }

    long long mn = sum, mx = sum, r1 = r;

    if (mex == 0)
    {
        long long x = a[l];
        for (long long i = l + 1; i <= r; i++)
            x = min(x, a[i]);
        mx = accumulate(a.begin(), a.end(), 0LL) - 2 * x;
        cout << mn << ' ' << mx << '\n';
        return;
    }

    while (r > l)
    {
        if (a[r] >= mex || f2[a[r]] > 1)
        {
            sum += 2 * a[r];
            if (a[r] < mex)
                f2[a[r]]--;
            r--;
        }
        else
            break;
    }

    mx = max(mx, sum);

    while (l < r1) // n
    {
        if (a[l] < mex)
            f2[a[l]]--;
        sum += 2 * a[l];

        while (a[l] < mex && f2[a[l]] == 0 && r < r1)
        {
            r++;
            if (a[r] < mex)
                f2[a[r]]++;
            sum -= 2 * a[r];
        }

        if (a[l] < mex && f2[a[l]] == 0)
            break;
        
        mx = max(mx, sum);
        l++;
    } // 2*n = n
    // we are trying to take the lowest sized gap here such that 
    // in that gap all values from 0 to mex-1 come atleast once
    // this way this gap can be treated as a middle portion and can be taken to form
    // a possible answer 

    cout << mn << ' ' << mx << '\n';
}

// tc = O(N) = O(2*10^5)
// sc = O(N) = O(2*10^5)

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}