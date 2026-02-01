int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        if (x % 2 == 1)
            cout << -1 << "\n";
        else
        {
            int flag = 1;
            long long y = x / 2;
            long long a = 0, b = 0;
            long long pos = 0;
            while (y || x)
            {
                if ((y & 1) && (x & 1))
                {
                    flag = 0;
                    break;
                }
                else if ((y & 1) && !(x & 1))
                {
                    a |= (1LL << pos);
                    b |= (1LL << pos);
                }
                else if (!(y & 1) && (x & 1))
                {
                    a |= (1LL << pos);
                }
                y >>= 1;
                x >>= 1;
                pos++;
            }
            if (flag == 0)
                cout << -1 << "\n";
            else
                cout << a << " " << b << "\n";
        }
    }
    return 0;
}

// Time Complexity: O(log x) for each test case
// Space Complexity: O(1)