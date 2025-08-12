class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int ans = 0;

        map<int, int> mp;

        int n = nums.size();

        vector<int> pref(n, 0);

        pref[0] = nums[0];

        // [1,-1,0] --->  [1,0,0]   k = 0;

       
        for (int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i - 1] + nums[i];

           
        }

        for (int i = 0; i < pref.size(); i++) {

            if (pref[i] == k) {

                ans++;

            }
           

                int left = pref[i] - k;

                if (mp.find(left) != mp.end()) {

                    ans+=mp[left];

                   

                    if (mp[left] == 0) {
                        mp.erase(left);
                    }

                }
            

              mp[pref[i]]++;

           
        }

         

      

        return ans;
    }
};