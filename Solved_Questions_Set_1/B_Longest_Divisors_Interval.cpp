#include <bits/stdc++.h>
using namespace std;

// long long gcd(long long a, long long b){if (b == 0)return a;return gcd(b, a % b);} //__gcd

// i can find the lcm of [l,r] where l starts from 1. and i can maybe find a upperbound of how big r can be

int main()
{
    // long long a = 1;
    // for(long long i=2;i<=40;i++)
    // {
    //     a = (a*i)/gcd(a,i);
    // }
    // cout<<a<<endl;

    // gcd(a,b) * lcm( a,b) = a*b
    // lcm(a,b) = a*b / gcd(a,b)

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        // taking input

        int c = 0;
        for (int i = 1; i<=50 ; i++)
        {
            if (n % i == 0)
                c++;
            else
                break;
        }
        cout << c << endl;

    }
    return 0;
}

// time complexity - O(50) ~ O(logN)
// space complextiy - O(1)
