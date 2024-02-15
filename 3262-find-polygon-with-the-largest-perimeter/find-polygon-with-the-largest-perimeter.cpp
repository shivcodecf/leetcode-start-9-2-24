class Solution {
public:
#define ll  long long
    long long largestPerimeter(vector<int>& nums) {



      sort(nums.begin(),nums.end());
      ll maxi=-1,c=0;
      ll sum=0;
      ll n=nums.size(),check=0,sum1=0;
      
      
      if(nums.size()<3)
      {
          return -1;
      }
      vector<ll>pref(n);
      pref[0]=nums[0];
     
      for(int i=1;i<n;i++)
      {
       pref[i]+=pref[i-1];
       
        pref[i]+=nums[i];
      
       
      }
      for(int i=0;i<n-1;i++)
      {    

          if(pref[i]>nums[i+1])
          {
             
              maxi=max(maxi,(ll)pref[i+1]);
              
          }
      }
     

    






   

     
      
          return maxi;
      
     


    }
};