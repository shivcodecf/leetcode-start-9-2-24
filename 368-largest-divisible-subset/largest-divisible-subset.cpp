#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

     
         sort(nums.begin(),nums.end());

         map<int,int>mp;
         int n=nums.size();

         vector<int>t(n,1);
         vector<int>prev(n,-1);
         int maxi=-1,index=-1;

        

         for(int i=0;i<n;i++)
         {   
           
            
            for(int j=0;j<i;j++)
            { 
                
                if((nums[i]%nums[j])==0 && t[j]+1>t[i])
                {
                   t[i]=max(t[i],t[j]+1);
                   prev[i]=j;
                }
             
            }

            if(t[i]>maxi)
            {
                maxi=t[i];
                index=i;

            }

           



         }

         vector<int>ans;

         while(index!=-1)
         {
            ans.push_back(nums[index]);
            index= prev[index];
         }

         return ans;

        




    }
};