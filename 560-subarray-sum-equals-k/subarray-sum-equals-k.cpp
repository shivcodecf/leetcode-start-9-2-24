class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int ans = 0;

        map<int, int> mp;

        int n = nums.size();

        vector<int> pref(n, 0);

        pref[0] = nums[0];

        // why we need this (mp[0]=1), below is tc 
        // [1,-1]
        // below is prefix Sum
        // [1,0] --> here if we not store (mp[0]=1) then , we not get my answer. that its, we need .

        mp[0] = 1;




        

        for (int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        for (int i = 0; i < pref.size(); i++) {

          

            int left = pref[i] - k;

            if (mp.find(left) != mp.end()) {

           // why here , we need to add all required frequencies, here is the tc which will clear all doubts

         //  --> [1,-1,0]  --> prefSum = [1,0,0] 
         // here , if we not take all prev frequencies , then its will give wrong answer.here is few also expamles

         // [2,3,5,-10,0] --> [2,5,10,0,0] --> 

                ans += mp[left];

                
            }

            mp[pref[i]]++;
        }

        return ans;
    }
};