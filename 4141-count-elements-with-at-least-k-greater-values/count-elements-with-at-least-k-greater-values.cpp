class Solution {
public:
    int countElements(vector<int>& nums, int k) {

        int n = nums.size();

        long long ans = 0;

        sort(nums.begin(), nums.end());

        map<int, int> mp, mp1;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            mp1[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {

            mp[nums[i]]--;

            int x =(n-1-i)-mp[nums[i]];

            if(x>=k)
            {
                ans++;
            }

          
        }

        return ans;
    }
};