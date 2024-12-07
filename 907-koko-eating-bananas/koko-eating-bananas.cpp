class Solution {
   
   int solve(int mid,vector<int>& piles,int h)
   { 

    long long sum=0;

    for(int i=0;i<piles.size();i++)
    {
      sum+=(piles[i]+mid-1)/mid;

    }

    return sum<=h;

   }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int high = *max_element(piles.begin(),piles.end());

        int low = 1,ans = INT_MAX;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(solve(mid,piles,h))
            {  
                ans = min(ans,mid);
                high = mid-1;
               
            }
            else {
                low = mid+1;
            }


        }

        return ans;

    }
};