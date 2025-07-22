class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;

        map<int, vector<int>> mp;
        for (auto& p : points) {
            mp[p[1]].push_back(p[0]);
        }

        vector<long long> v;
        for (auto& it : mp) {
            int l = it.second.size();
            if (l >= 2) {
                long long pairs = (1LL * l * (l - 1) / 2) % MOD;
                v.push_back(pairs);
            }
        }

        long long totalSum = 0;

        long long squareSum = 0;

        for (long long val : v) {

            totalSum = (totalSum + val) % MOD;
            
            squareSum = (squareSum + (val * val) % MOD) % MOD;

        }

        // total = (S*S - sum of squares) / 2 % MOD
        long long total = (totalSum * totalSum) % MOD;
        total = (total - squareSum + MOD) % MOD;

        // Modular inverse of 2 modulo MOD = 500000004
        return (int)((total * 500000004LL) % MOD);
    }
};
