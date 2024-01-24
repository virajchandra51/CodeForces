#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        // taking input

        int maxPackageSize = -1;
        // if i maximise the size/number of shovels of each package
        // then i require lower packages

        for (int i = 1; i * i <= n; i++)
        {
            // finding factors in sqrt(n)
            if (n % i == 0)
            {
                // i * (n/i) = n
                int packageSize1 = i;     // this is i
                int packageSize2 = n / i; // this is n/i

                // if this packageSize1 is feasible ie <=k
                if (packageSize1 <= k)
                    maxPackageSize = max(maxPackageSize, packageSize1);

                // if this packageSize2 is feasible ie <=k
                if (packageSize2 <= k)
                    maxPackageSize = max(maxPackageSize, packageSize2);
            }
        }
        int packageCount = n / maxPackageSize;
        cout << packageCount << endl;
    }
    return 0;
}

// time complexity - O(sqrt n)
// space complexity - O(1)