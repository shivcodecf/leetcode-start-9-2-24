#define ll long long
class Solution {
public:  
       
    ll solve(vector<int>& piles,ll ind,ll h,ll mid)
    {   
        ll hour=0,sum=0;
        for(int i=0;i<piles.size();i++)
        {  
          ll d = piles[i]/mid;
          ll r= piles[i]%mid;
          if(mid>=piles[i])
          {
            hour++;
          }
          else {
             hour+=d;
             if(r!=0)
             {
                hour++;
             }
          }
        }

        return hour;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        
    ll low = 1;

    ll high = *max_element(piles.begin(),piles.end());

    ll mid=0,ans=0;

    while(low<=high)
    {
        mid = low+(high-low)/2;
      

        ll res = solve(piles,0,h,mid);

        if(res>h)
        {
          low = mid+1;

        }
        else {
            ans = mid;
            high = mid-1;
         
        }

    }

    return ans;

    }
};