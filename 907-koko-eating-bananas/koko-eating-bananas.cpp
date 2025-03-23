class Solution {
       
       bool solve(vector<int>& piles,int mid,int h)
       {  

        long long ans =0;

        for(int i=0;i<piles.size();i++)
        {
            ans+=(piles[i]+mid-1)/mid;
        }

        return ans<=h;


       }

public:
    int minEatingSpeed(vector<int>& piles, int h) {


        int maxi = *max_element(piles.begin(),piles.end());
        
        int low = 1, high = maxi,ans = INT_MAX;


        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(solve(piles,mid,h))
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