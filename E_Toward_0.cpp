// 2024-04-20 22:23:13
// Viraj Chandra
// Linkedin: https://www.linkedin.com/in/viraj-chandra-4073a8223/
// Codeforces: https://codeforces.com/profile/khnhcodingkarlo
// Codechef: https://www.codechef.com/users/codecozkhnhs

#include <bits/stdc++.h>

using namespace std;

map<long long, long double> m;

double helper(long double N, long double A, long double X, long double Y)
{
    if (N == 0)
        return 0;
    if (m.count(N))
    {
        return m[N];
    }
    long double a = X + helper(floor(N / A), A, X, Y), b = Y * 6.0;
    for (int B = 2; B <= 6; B++)
        b += helper(floor(N / B), A, X, Y);
    b /= 5.0;
    m[N] = min(a, b);
    return min(a, b);
}

int32_t main()
{
    // Rating? Neh. In love with experience.
    // Code Karlo, Coz KHNH :)
    auto solve = [&]()
    {
        long long N, A, X, Y;
        cin >> N >> A >> X >> Y;
        // cout << N << " " << A << " " << X << " " << Y << endl;
        cout << fixed << setprecision(7) << helper(N, A, X, Y) << endl;
    };

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}