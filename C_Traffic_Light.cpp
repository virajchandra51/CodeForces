#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        char color;
        cin >> color;
        string s;
        cin >> s;
        s += s;
        vector<long long> index_of_green;
        for (int i = 0; i < n * 2; i++)
        {
            if (s[i] == 'g')
                index_of_green.push_back(i);
        }

        long long max_seconds = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == color)
            {
                auto next_green_index = *lower_bound(index_of_green.begin(), index_of_green.end(), i);
                long long difference = next_green_index - i;
                max_seconds = max(max_seconds, difference);
            }
        }
        cout << max_seconds << endl;
    }
    return 0;
}