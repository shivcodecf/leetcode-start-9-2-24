class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long flag=0,sum=0,x=0,c=0,c1=0;
        map<int,int>mp;
         for(long long i=0;i<nums.size()-1;i++)
         {
             if(nums[i]==nums[i+1])
             {
                 if(nums[i]==0 && nums[i+1]==0)
                 {
                     return true;
                 }
             }
         }
         for(long long i=0;i<nums.size();i++)
         {
             if(nums[i]==0)
             {
                 c++;
             }
             if(nums[i]%k==0 && nums[i]>0)
             {
                 c1++;
             }
         }
         if(c>0 && c1>0)
         {
             return true;
         }

       for(long long i=0;i<nums.size();i++)
       { 
         sum+=nums[i];
         x= sum%k;
         if(mp.find(x)!=mp.end())
         {
            if(mp[x]!=i)
            {
                return true;
            } 
         }
         if(x==0 && mp.size()>0)
         {
             return true;
         }

         mp[x]=i+1;


       }
       return false;
           
    }
};