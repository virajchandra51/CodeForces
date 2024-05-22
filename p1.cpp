#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        stack<long long> stk;
        stack<int> in;
        long long cost = 0;

        for (int i = 0; i < n; ++i) {
            while (stk.size() > 1 && stk.top() > a[i]) {
                long long v1 = stk.top();
                stk.pop();
                if (v1 >= stk.top()) {
                    in.pop();
                } else {
                    stk.push(v1);
                    break;
                }
            }
            stk.push(a[i]);
            in.push(i);
        }

        long long last = stk.top();
        stk.pop();
        int j = in.top();
        in.pop();

        while (!stk.empty()) {
            cost += max(last, stk.top()) * (j - in.top());
            last = stk.top();
            stk.pop();
            j = in.top();
            in.pop();
        }
        
        cout << cost << "\n";
    }

    return 0;
}