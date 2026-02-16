int main()
{
    int t;
    cin >> t;
    while (t--)
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

        bool found = false;

        for (int i = 0; i <= min(8LL, number_of_2s); i++)
        {
            for (int j = 0; j <= min(2LL, number_of_3s); j++)
            {
                long long sum = sum_of_digits + 2 * i + 6 * j;
                if (sum % 9 == 0)
                    found = true;
            }
        } // 9 * 3 = 27

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

// Time Complexity - O(len)
// Space Complexity - O(len)