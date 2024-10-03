class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       

      int n=nums.size();

      vector<int>pref(n,0);

      pref[0] = nums[0];

      int sum = nums[0];

     for(int i=1;i<n;i++)
     { 

        pref[i] = (pref[i-1] + nums[i])%p;

        sum = (sum+nums[i])%p;

     }

        map<int,int>mp;

       int target = sum%p, ans = INT_MAX;

       if(target==0)
       { 

        return 0;

       }

       mp[0] = -1;
       int curr =0;

     for(int i=0;i<n;i++)
     {   

           curr = (curr+nums[i])%p;
           
          int prev = (curr - target+p)%p;

          if(mp.find(prev)!=mp.end())
          { 

            ans = min(ans,i-mp[prev]);


          }

            mp[curr%p] = i;

     }
     

     return ans == n ? -1 : ans;





    }
};