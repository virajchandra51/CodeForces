#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long k;
        cin >> k;

        long long len = 1; // Length of the numbers in the current block
        long long count = 9; // Count of numbers in the current block
        long long start = 1; // Starting number of the current block

        // count * len gives the total number of digits in the current block
        
        // Find the block
        while (k > count * len)
        {
            k -= count * len;
            len++;
            count *= 10;
            start *= 10;
        }

        // Find the number
        long long number = start + (k - 1) / len;
        string s = to_string(number);

        // Output the digit
        cout << s[(k - 1) % len] << '\n';
    }

    return 0;
}

// Time Complexity: O(log 10 (k)) per query
// Space Complexity: O(1)