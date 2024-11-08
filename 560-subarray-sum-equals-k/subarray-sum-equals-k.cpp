class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
       map<int,int>mp;

       int n = nums.size();

       vector<int>pref(n);

       pref[0] = nums[0];

       for(int i=1;i<n;i++)
       {
        pref[i] = pref[i-1]+nums[i];
       }

       int ans=0;

       for(int i=0;i<nums.size();i++)
       {
        

        if(pref[i]==k)
        {
            ans++;
        }

        int check = (pref[i]-k);

        if(mp.find(check)!=mp.end())
        {
            ans+=mp[check];
        }

        mp[pref[i]]++;



       }

       return ans;


    }
};