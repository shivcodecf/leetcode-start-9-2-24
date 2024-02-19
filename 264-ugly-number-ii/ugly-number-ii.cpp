class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> ugly(n);
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int next_multiple_of_2 = 2;
        int next_multiple_of_3 = 3;
        int next_multiple_of_5 = 5;
        
        for (int i = 1; i < n; ++i) {
            int next_ugly = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
            ugly[i] = next_ugly;
            if (next_ugly == next_multiple_of_2) {
                p2++;
                next_multiple_of_2 = ugly[p2] * 2;
            }
            if (next_ugly == next_multiple_of_3) {
                p3++;
                next_multiple_of_3 = ugly[p3] * 3;
            }
            if (next_ugly == next_multiple_of_5) {
                p5++;
                next_multiple_of_5 = ugly[p5] * 5;
            }
        }
        return ugly[n - 1];
    }
};
