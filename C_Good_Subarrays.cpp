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

        string s;
        cin >> s;

        map<long long, long long> m;
        m[0]=1;

        long long preS = 0;
        for (int i = 1; i <= n; i++) // n
        {
            preS += (s[i-1]-'0');
            m[(preS-i)]++; // logn
        } // nlogn

        long long answer = 0;
        for (auto it : m) // n
        {
            answer += (it.second * (it.second - 1) / 2);
        }
        cout << answer << endl;
    }

    return 0;
}

// 1-0 = 1
// 2-1 = 1
// 2-2 = 0
// 3-3 = 0
// 4-4 = 0



// tc - O(nlogn) - 10^5~10^6
// sc - O(n)
