#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

      int maxi=*max_element(nums.begin(),nums.end());

      map<int,int>mp;
      int n=nums.size();

      int i=0,j=0,cnt=0,res=0,ans=0;
      vector<int>temp;

      while(i<n && j<n)
      {
          if(nums[i]==maxi)
          {
             cnt++;

          }  
          if(nums[i]!=maxi && temp.size())
          {
            
                ans=temp.back(); 
                temp.push_back(ans);
            
            
          }
         
         
     
            if(cnt==k)
            {
           while(cnt==k && j<n)
           { 
              res++;  
              if(nums[j]==maxi)
             {
                cnt--;
            
             }
             
            
             j++; 

             

           } 
         
           

           ans=res;
           
           if(temp.size())
           {
            ans+=temp.back();
           }
           temp.push_back(ans);
           res=0;
           
           

            }
        
        i++;

      }
      long long ans1=0;

      for(int i=0;i<temp.size();i++)
      {
       ans1+=temp[i];
      } 


      return ans1;

    }
};