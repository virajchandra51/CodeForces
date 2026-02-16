int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long f1 = 2 * a - b;
        long long f2 = 2 * b - a;
        if (f1 >= 0 && f1 % 3 == 0 && f2 >= 0 && f2 % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

// Time Complexity = O(1) per test case
// Space Complexity = O(1) per test case