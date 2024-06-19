class Solution {
public: 
      
      int solve(vector<int>& bloomDay,int ban,int adj,int mid)
      {
          int cnt=0,total=0;
         for(int i=0;i<bloomDay.size();i++)
         {
             if(mid>=bloomDay[i])
             {   

                cnt++;
              if(cnt==adj)
              {
                  total++;
                  cnt=0;
              }


             }
             else {
               cnt=0;
             }
         }
         return total;

      }



     int minDays(vector<int>& bloomDay, int m, int k) {
        

     int maxi = *max_element(bloomDay.begin(),bloomDay.end());

     int mini=1,ans=INT_MAX,mid=0;

    while(mini<=maxi)
    {
        mid= mini+(maxi-mini)/2;
        if(solve(bloomDay,m,k,mid)>=m){
            ans=min(ans,mid);
            maxi=mid-1;

        }
        else {
            mini=mid+1;
        }
        




    }
    if(ans!=INT_MAX)
    return ans;
    return -1;
      


    }
};