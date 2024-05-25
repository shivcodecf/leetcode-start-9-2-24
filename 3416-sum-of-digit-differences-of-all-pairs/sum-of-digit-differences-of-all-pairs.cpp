#define ll long long

class Solution {

map<int,map<char,ll>>mp;
ll ans=0;

public:  

   void solve(ll num)
   { 

     string s=to_string(num);

     for(int i=0;i<s.size();i++)
     {
        mp[i][s[i]]++;
     }

   }
  

    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();


        for(ll i=0;i<n;i++)
        {
          solve(nums[i]);
        }

        for(int i=0;i<n;i++)
        {
            string s=to_string(nums[i]);

            for(int j=0;j<s.size();j++)
            {
                ans+= n-(mp[j][s[j]]);
            }

        }

        return  ans/2;




    }
};