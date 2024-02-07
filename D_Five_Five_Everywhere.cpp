#include <bits/stdc++.h>
using namespace std;

// Constants
vector<long long> primes;
vector<bool> is_prime;

// Mathematical functions
void Sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = false;
}

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}

int main()
{
    Sieve(55556);
    get_primes(55556);
    int n;
    cin >> n;
    // taking input

    int c = 0;

    // int count = 0;
    // for(auto it:primes) if(it%5==2) count++;
    // cout<<count<<endl;

    for(auto it:primes) // O(55555)
    {
        if(c==n) break;
        if(it%5==1) cout<<it<<" ", c++;
    }
    cout<<endl;

    return 0;
}

// TC - O(n*log(logn)) ~ 10^5 10^4
// SC - O(10^3-10^4)
