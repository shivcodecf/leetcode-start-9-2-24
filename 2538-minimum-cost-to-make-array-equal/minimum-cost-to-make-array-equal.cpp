
#define ll long long

class Solution { 

   ll solve(vector<int>& nums, vector<int>& cost,ll mid)
   { 

    ll sum=0;

    for(int i=0;i<nums.size();i++)
    {
       sum+=abs(mid-nums[i])*cost[i];
    }

    return sum;

   }


public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
    //  sort(nums.begin(),nums.end());

     int n= nums.size();

     int low = *min_element(nums.begin(),nums.end());

      int high = *max_element(nums.begin(),nums.end());

     ll ans=INT_MAX;

     while(low<=high)
     {
        int mid = low+(high-low)/2;

        ll cost1 = solve(nums,cost,mid);

        ll cost2 = solve(nums,cost,mid+1);

         ans = min(cost2,cost1);

        if(cost1<cost2)
        {
          high = mid-1;
         
        }
        else {
            // ans = min(ans,cost2);
            low = mid+1;
        }

        

        


     }

     return ans;



    }
};