class Solution {
public: 
#define ll long long
ll ans=-1,mini=INT_MAX;


  ll solve(vector<int>& piles,int  n,int  mid)
  {     
      ll res=0;
       
      for(int i=0;i<n;i++)
      { 
          ll x=ceil(piles[i]/(double)mid);
          res+=x;
      }
      return res;
  }





    int minEatingSpeed(vector<int>& piles, int h) {
       
       
       ll low = 1, high = *(max_element(piles.begin(), piles.end()));
       

      while(low<=high)
      {   

          int  mid= low+(high-low)/2;
         

         long long res= solve(piles,piles.size(),mid);

          if(res<=h)
          {
              ans=mid;
             
              high=mid-1;
             
          }
          
          else {
              low=mid+1;

          }
          
      }
      return ans;

    }
};