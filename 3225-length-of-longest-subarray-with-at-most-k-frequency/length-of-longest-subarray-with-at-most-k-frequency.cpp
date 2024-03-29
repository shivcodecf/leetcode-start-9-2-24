
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

      
      int n=nums.size(),i=0,j=0,ans=0,maxi=0;
      map<int,int>mp;

      while(i<n && j<n)
      { 

       mp[nums[i]]++;

       if(mp[nums[i]]<=k)
       {
        ans=i-j+1;
        maxi=max(maxi,ans);

       }
       else{
         while(mp[nums[i]]>k && j<n)
         {  
               mp[nums[j]]--; 
             
             

             j++;

         } 
          ans=i-j+1; 
         maxi=max(maxi,ans);

       }
       cout <<maxi<<" ";
       i++;

      }
     return maxi;
        
    }
};