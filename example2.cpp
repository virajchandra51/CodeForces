int findGCDEx(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    int x1, y1;
    int d = findGCDEx(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main()
{
    int a = 17;
    int b = 5;
    int x, y;
    int gcd = findGCDEx(a, b, x, y);
    cout << "GCD: " << gcd << endl;
    cout << "Coefficients: x = " << x << ", y = " << y << endl;
}

// Time Complexity: O(log(min(a, b)))

long long inverse(long long a, long long m)
{
    long long x, y;
    long long g = findGCDEx(a, m, x, y);
    if (g != 1)
        return -1;            // no inverse exists
    return ((x % m) + m) % m; // x can be negative,
}

// Time Complexity: O(log(m))