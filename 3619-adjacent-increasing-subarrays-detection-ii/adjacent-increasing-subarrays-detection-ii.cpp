class Solution {

    bool solve(vector<int>& pref, int mid) {

        for (int i = mid-1; i+mid<=pref.size()-1; i++) {

            if (pref[i] >= mid && pref[i + mid] >= mid) {
                return true;
            }
        }

        return false;
    }

public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int n = nums.size();

        vector<int> pref(n, 1);

        for (int i = 0; i < n; i++) {

            if (i == 0) {
                pref[i] = 1;
                continue;
            }

            if (nums[i] > nums[i - 1]) {
                pref[i] = pref[i - 1] + 1;
            } else {
                pref[i] = 1;
            }
        }

        int left = 1, right = n;

        int ans = 0;
        for(int i=0;i<pref.size();i++)
        {
            cout <<pref[i]<<" ";
        }

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (solve(pref, mid)) {

                ans = mid;
                left = mid + 1;

            } else {

                right = mid - 1;
            }
        }

        return ans;
    }
};