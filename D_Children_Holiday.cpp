#include <bits/stdc++.h>
using namespace std;

// Function to check if all balloons can be inflated within time T
bool canInflate(int m, int n, vector<vector<int>>& assistants, int T) {
    int total = 0;
    for (auto& assistant : assistants) {
        int t = assistant[0], z = assistant[1], y = assistant[2];
        int fullCycles = T / (t * z + y);
        int remainingTime = T % (t * z + y);
        int balloons = fullCycles * z + min(z, remainingTime / t);
        total += balloons;
        if (total >= m) return true;
    }
    return total >= m;
}

// Function to find the minimum time required to inflate all balloons
int findMinTime(int m, int n, vector<vector<int>>& assistants) {
    int left = 0, right = m * 1000; // Upper bound for time
    while (left < right) {
        int mid = (left + right) / 2;
        if (canInflate(m, n, assistants, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// Function to assign balloons to assistants
vector<int> assignBalloons(int m, int n, vector<vector<int>>& assistants, int T) {
    vector<int> balloons(n, 0);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int t = assistants[i][0], z = assistants[i][1], y = assistants[i][2];
        int fullCycles = T / (t * z + y);
        int remainingTime = T % (t * z + y);
        balloons[i] = fullCycles * z + min(z, remainingTime / t);
        total += balloons[i];
        if (total >= m) {
            balloons[i] -= (total - m);
            break;
        }
    }
    return balloons;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> assistants(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> assistants[i][0] >> assistants[i][1] >> assistants[i][2];
    }

    if (m == 0) {
        cout << 0 << endl;
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        cout << endl;
        return 0;
    }

    int T = findMinTime(m, n, assistants);
    vector<int> balloons = assignBalloons(m, n, assistants, T);

    cout << T << endl;
    for (int i = 0; i < n; ++i) {
        cout << balloons[i] << " ";
    }
    cout << endl;

    return 0;
}