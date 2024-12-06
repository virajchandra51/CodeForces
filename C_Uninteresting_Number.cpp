#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    long long number_of_2s = 0;
    long long number_of_3s = 0;
    long long sum_of_digits = 0;
    for (auto c : s) // len
    {
        if (c == '2')
            number_of_2s++;
        else if (c == '3')
            number_of_3s++;
        sum_of_digits += c - '0';
    }

    long long diff_to_cover = (9 - sum_of_digits % 9) % 9;

    for (long long b = 0; b <= number_of_3s; b++) // len
    {
        long long new_diff_to_cover = (diff_to_cover - 6LL * b) % 9;

        if (new_diff_to_cover < 0)
            new_diff_to_cover += 9;

        long long a = (new_diff_to_cover * 5) % 9;
        if (a <= number_of_2s)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

// tc - O(len)
// sc - O(len)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}