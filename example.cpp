// Count of Divisors
// p, k = prime factor and its exponent

long long divisorCount(vector<long long> &k)
{
    long long total = 1;
    for (long long ki : k)
        total = total * ((ki + 1) % MOD) % MOD;
    return total;
}

// Sum of Divisors
// p, k = prime factor and its exponent

long long divisorSum(vector<long long> &p, vector<long long> &k)
{
    long long total = 1;
    for (int i = 0; i < (int)p.size(); i++)
    {
        long long top = (binpowmod(p[i], k[i] + 1, MOD) - 1 + MOD) % MOD;
        long long bottom = (p[i] - 1) % MOD;
        total = total * top % MOD * inverse(bottom) % MOD;
    }
    return total;
}

// Product of Divisors
// p, k = prime factor and its exponent

const long long MOD = 1e9 + 7;
const long long EXPM = MOD - 1;

long long sumOfPowers(long long k)
{
    long long a = k, b = k + 1;
    if (a % 2 == 0)
        a /= 2;
    else
        b /= 2;
    return (a % EXPM) * (b % EXPM) % EXPM;
}

long long divisorProduct(vector<long long> &p, vector<long long> &k)
{
    int m = p.size();

    vector<long long> before(m + 1, 1), after(m + 1, 1);
    for (int i = 0; i < m; i++)
        before[i + 1] = before[i] * ((k[i] + 1) % EXPM) % EXPM;
    for (int i = m - 1; i >= 0; i--)
        after[i] = after[i + 1] * ((k[i] + 1) % EXPM) % EXPM;
    
    // before[i] = product of (k[j] + 1) for j = 0 to i-1
    // after[i] = product of (k[j] + 1) for j = i+1 to m-1
    // before[i] * after[i + 1] = product of (k[j] + 1) for j = 0 to i-1 and j = i+1 to m-1
    // basically everything except k[i]

    long long answer = 1;
    for (int i = 0; i < m; i++)
    {
        long long othersMake = before[i] * after[i + 1] % EXPM;
        long long exponent = sumOfPowers(k[i]) * othersMake % EXPM;
        answer = answer * pw(p[i], exponent, MOD) % MOD;
    }
    return answer;
}