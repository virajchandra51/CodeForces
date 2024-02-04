#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    cout<<endl;
    // taking input

    map<long long, char> m;
    m[1] = '(';
    m[2] = ')';
    m[3] = '[';
    m[4] = ']';
    // creating map of values to their bracket type in q

    stack<long long> RBrac, SBrac, AltDepth;
    RBrac.push(0);
    SBrac.push(0);
    AltDepth.push(0);
    // stack to store Round Brackets indexes,
    // Sqaure Brackets indexes and latest Alternating Depth

    // max alternating depth, maxRound , maxSquare variables
    long long maxDepth = 0;
    long long maxR = 0;
    long long maxS = 0;

    for (int i = 1; i <= n; i++)
    {
        char ch = m[v[i-1]];
        if (ch == '(')
        {
            // Now I need to see that before this ( bracket was there a [ bracket
            // if yes Then I know my depth has increased else depth remained same
            if (RBrac.top() <= SBrac.top())
                AltDepth.push(AltDepth.top() + 1);
            else
                AltDepth.push(AltDepth.top());
            // now I'll push this i index in RBrac since I am storing indexes of round brackets
            RBrac.push(i);
        }
        else if (ch == '[')
        {
            // similar analogy as for ( bracket
            if (SBrac.top() <= RBrac.top())
                AltDepth.push(AltDepth.top() + 1);
            else
                AltDepth.push(AltDepth.top());
            SBrac.push(i);
        }
        else if (ch == ')')
        {
            // if I have a closing round bracket then I can check the length of the segment
            // between this round bracket with its pair of opening round bracket
            maxR = max(maxR, i - RBrac.top() + 1); // Eq as above
            RBrac.pop();                           // Remove this bracket as it is matched!
            AltDepth.pop();                        // Remove this depth as it is matched!
        }
        else
        {
            // similar analogy as ] bracket
            maxS = max(maxS, i - SBrac.top() + 1); // Eq as above
            SBrac.pop();                           // Remove this bracket as it is matched!
            AltDepth.pop();                        // Remove this depth as it is matched!
        }
        // outside all if checks I compare the current Alternating depth with my varible
        maxDepth = max(maxDepth, AltDepth.top()); // Max depth in sequence
    }
    cout << maxDepth << " " << maxR << " " << maxS << " " << endl;
    return 0;
}

//TC - O(n)
//SC - O(n+n+n+4) - O(n)