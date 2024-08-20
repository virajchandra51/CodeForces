// #include <iostream> // used for input output
#include <bits/stdc++.h>
using namespace std;
// std - standard

// online assessment - internships / placements

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout<<1<<'\n';
//     printf("2\n");
//     cout<<3<<'\n';
//     printf("4\n");
//     return 0;
// }

// int main()
// {
//     vector<int> v = {1, 2, 3, 4, 5};
//     return 0;
// }

// int main()
// {
//     cout<<a<<endl;
//     return 0;
// }

// int main()
// {
//     long long a[] = {5000000000000,505050505005,4,8,2};
//     long long answer = LONG_MIN; // -2^63
//     for(int i=0; i<5; i++)
//     {
//         cout<<"Before taking maximum "<<answer<<endl;
//         answer = max(answer, a[i]);
//         cout<<"After taking maximum "<<answer<<endl;
//         cout<<endl;
//     }
//     cout<<answer<<endl;
//     return 0;
// } // trick to find minimum and maximum in an array


// int main()
// {
//     double answer = 1000848.2354682850;
//     cout<<fixed<<setprecision(6)<<answer<<endl;
//     return 0;
// }


// int main()
// {
//     int answerMax = 10^10;
//     int answerMin = INT_MIN+1;
//     cout<<answerMax<<endl;
//     cout<<answerMin<<endl;
//     return 0;
// }

// tle - time limit exceeded
// mle - memory limit exceeded
// wa - wrong answer
// ac - accepted
// runtime error - re
// segmentation fault - segfault
// sigabrt - abort signal

// int main()
// {
//     int answerMax = 
//     int answerMin = INT_MIN+1;
//     cout<<answerMax<<endl;
//     cout<<answerMin<<endl;
//     return 0;
// }



int main()
{
    auto begin = chrono::high_resolution_clock::now();
    int iter = 10000;
    for (int i = 0; i < iter; i++)
    {
        cout << '\n';
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - begin);
    printf("Time taken for %d iterations: %lld microseconds\n", iter, duration.count());
    return 0;
}

// int main()
// {
//     int a[] = {1, 5, 4, 2, 3};
//     sort(a, a+5);
//     cout<<a[4]<<endl;
//     return 0;
// }