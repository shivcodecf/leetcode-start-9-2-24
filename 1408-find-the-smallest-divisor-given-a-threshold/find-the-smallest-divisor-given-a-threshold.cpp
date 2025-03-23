class Solution {
    
    bool solve(int mid,int check,vector<int>& nums)
    {  
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
          ans+=(nums[i]+mid-1)/mid;
        }

        return ans<=check;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {

       int low = 1,high = *max_element(nums.begin(),nums.end());

       int ans = INT_MAX;


       while(low<=high)
       { 

        int mid = low+(high-low)/2;

        if(solve(mid,threshold,nums))
        { 

            ans = min(ans,mid);

            high = mid-1;

        }
        else{
            low = mid+1;
        }

       } 


       return ans;

    }
};