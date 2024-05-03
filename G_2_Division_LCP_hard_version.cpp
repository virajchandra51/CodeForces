#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);
    for(int i = 1; i < n; i++) {
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    z[0] = n;
    return z;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, L, R;
        cin >> n >> L >> R;

        string str;
        cin >> str;

        vector<int> z = z_function(str);
        vector<int> ans(n + 1, 0);
        set<int> st;

        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; i++) pq.push({z[i], i});

        for (int l = n; l >= 1; l--) {
            while (!pq.empty() && pq.top().first == l) {
                st.insert(pq.top().second);
                pq.pop();
            }
            int i = 0;
            while (st.lower_bound(i) != st.end()) {
                ans[l]++;
                i = *st.lower_bound(i) + l;
            }
        }

        for (int k = L; k <= R; k++) {
            int l = lower_bound(ans.begin() + 1, ans.end(), k, [&] (int mid, int target) {
                return mid >= target;
            }) - ans.begin() - 1;
            cout << l << " \n"[k == R];
        }
    }
    
    return 0;
}