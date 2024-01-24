#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long mod = 1e9 + 7;

    long long n;
    cin >> n;
    // taking input

    map<long long, long long> freqOfPrimes;

    for (long long num = 1; num <= n; num++)
    {

        // basic code to find prime factors of a number in O(sqrt(n)) complexity
        long long copyNum = num;

        while (copyNum % 2 == 0)
        {
            freqOfPrimes[2]++;
            copyNum /= 2;
        }
        //divide by 2 till 2 is a factor
        for (long long i = 3; i * i <= copyNum; i += 2)
        {
            while (copyNum % i == 0)
            {
                freqOfPrimes[i]++;
                copyNum /= i;
            }
        }
        // take all rest prime factors
        if (copyNum > 2)
            freqOfPrimes[copyNum]++;

    }

    //coming out of loop I now have the frequency of the prime factors of N!

    // (a*b)%m = (a%m * b%m) %m

    long long divisors = 1;
    for (auto it : freqOfPrimes)
    {
        divisors = (divisors % mod * (it.second + 1) % mod) % mod;
    }

    // simple formula 
    // number of divisors = (a+1)(b+1)(c+1).... for n = p^a q^b r^c ..

    cout << divisors << endl;

    return 0;
}

// time complexity - O(n * sqrt(n))
// space complexity - O(n)