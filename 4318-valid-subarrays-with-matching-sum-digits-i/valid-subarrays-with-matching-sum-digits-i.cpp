class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {

        int n = nums.size();

        int ans = 0;

         for (int i = 0; i < n; i++) {
            long long sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (sum % 10 != x) continue;

                long long firstDigit = sum;
                while (firstDigit >= 10)
                    firstDigit /= 10;

                if (firstDigit == x)
                    ans++;
            }
        }

        return ans;
        
    }
};