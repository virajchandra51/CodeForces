int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long p = 1 << n;
    long long flag = 0;
    for (long long mask = 0; mask < p; mask++)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                sum += a[i];
            else
                sum -= a[i];
        }
        if (sum % 360 == 0)
            flag = 1;
    }
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

// Time Complexity: O(2^n * n)
// Space Complexity: O(n)