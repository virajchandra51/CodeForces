#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int countOfOnes = 0;
        while (n > 0)
        {
            if (n & 1)
                countOfOnes++;
            n >>= 1;
        } // ceil(log2(n))
        // n = 7
        // 111
        if (countOfOnes % 2 == 1)
            cout << "ODD" << endl;
        else
            cout << "EVEN" << endl;
    }
    return 0;
}