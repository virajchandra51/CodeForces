#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long int
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    string number;
    cin >> number;

    int found = false;
    int answer;

    typedef unsigned int u_int;

    for(u_int i = 0; i < number.size() && !found; i++)
    {
        if(number[i] == '8' || number[i] == '0')
            found = true, answer = number[i] - '0';
    }

    for(u_int i = 0; i < number.size() && !found; i++)
    {
        for(u_int j = i + 1; j < number.size() && !found; j++)
        {
            int first_digit = number[i] - '0', second_digit = number[j] - '0';
            int number_formed = 10*first_digit + second_digit;

            if(number_formed%8 == 0)
                found = true, answer = number_formed;
        }
    }

    for(u_int i = 0; i < number.size() && !found; i++)
    {
        for(u_int j = i + 1; j < number.size() && !found; j++)
        {
            for(u_int k = j + 1; k < number.size() && !found; k++)
            {
                int first_digit = number[i] - '0', second_digit = number[j]- '0', third_digit = number[k] - '0';
                int number_formed = 100*first_digit + 10*second_digit + third_digit;

                if(number_formed%8 == 0)
                {
                    answer = number_formed;
                    found = true;
                }
            }
        }
    }

    if(found)
        printf("YES\n%d\n", answer);
    else
        printf("NO\n");

    return 0;
}