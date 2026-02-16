#include <iostream>
using namespace std;



int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        long long x, y;
        cin >> x >> y;

        long long ans;
        if (x <= y)
        {
            // Vertical Line Values : Border Cells -- Top
            if (y % 2 == 0)
                ans = ((y - 1) * (y - 1) + 1) + (x - 1);
            else
                ans = (y * y) - (x - 1);
        }
        else
        {
            // Horizontal Line Values : Border Cells -- Left
            if (x % 2 == 0)
                ans = (x * x) - (y - 1);
            else
                ans = ((x - 1) * (x - 1) + 1) + (y - 1);
        }

        cout << ans << "\n";
    }

    return 0;
}

// Time Complexity = O(1) per test case
// Space Complexity = O(1) per test case