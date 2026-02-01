int main()
{
    long long n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long p = 1 << n;
    long long ans = 0;
    for (long long mask = 0; mask < p; mask++)
    {
        vector<long long> v;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                v.push_back(a[i]);
        }
        if (v.size() >= 2)
        {
            long long sum = 0;
            long long mn = 1e9 + 7, mx = -1;
            for (int i = 0; i < v.size(); i++)
            {
                sum += v[i];
                mn = min(mn, v[i]);
                mx = max(mx, v[i]);
            }
            if (sum >= l && sum <= r && (mx - mn) >= x)
                ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}

// Time Complexity: O(2^n * n)
// Space Complexity: O(n)