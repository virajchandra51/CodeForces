int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        // contribution of each bit
        vector<pair<long long, int>> bits; // (value, bit_index)

        for (int b = 0; b <= 30; b++) {
            long long cnt = 0;
            for (long long x : A) {
                if (x & (1LL << b))
                    cnt++;
            }
            long long value = cnt * (1LL << b);
            bits.push_back({value, b});
        }

        // sort by max contribution, tie -> smaller bit index
        sort(bits.begin(), bits.end(), [](auto &p1, auto &p2) {
            if (p1.first != p2.first)
                return p1.first > p2.first;
            return p1.second < p2.second;
        });

        long long X = 0;
        for (int i = 0; i < K; i++) {
            X |= (1LL << bits[i].second);
        }

        cout << X << "\n";
    }
    return 0;
}


