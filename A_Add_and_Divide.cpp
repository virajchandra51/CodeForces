#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        long long ans = INT_MAX;
        for (int addition = 0; addition < 32; addition++)
        {
            long long temp = b + addition;
            if (temp == 1)
                continue;
            long long temp_a = a;
            long long operations = addition;
            while (temp_a)
            {
                temp_a /= temp;
                operations++;
            }
            ans = min(ans, operations);
        }
        cout << ans << endl;
    }
}