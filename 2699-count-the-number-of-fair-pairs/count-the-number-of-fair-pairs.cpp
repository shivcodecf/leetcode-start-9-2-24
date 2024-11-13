class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        long long ans=0;

        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {    

            // if(nums[i]>upper)
            // {
            //     continue;
            // }

            long long left = lower-nums[i];

            long long low = lower_bound(nums.begin()+i+1,nums.end(),left)-nums.begin();

            cout<<low<<endl;

           

            if(low>=nums.size())
            {
                continue;
            }

            if(nums[i]+nums[low]>upper)
            {
                continue;
            }

            long long start = low,end = nums.size()-1,check=low;

            while(start<=end)
            {
              long long mid = start + (end-start)/2;

            

              if(nums[i]+nums[mid]>=lower && nums[i]+nums[mid]<=upper)
              {  
                   check = mid;
                   start = mid+1;
              }
              else {
                 end = mid-1;
              }

            }
            
             ans+=check-low+1;
 


        }

        return ans;

    }
};