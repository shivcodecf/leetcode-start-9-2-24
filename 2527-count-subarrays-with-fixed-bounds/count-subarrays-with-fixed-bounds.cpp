class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long temp = -1, maxi = -1,mini =-1,ans=0;


        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxK || nums[i]<minK)
            {
                temp = i;
            }

            if(nums[i]==minK)
            {
                mini = i;
            }

            if(nums[i]==maxK)
            {
                maxi = i;
            }

            int check = min(maxi,mini);

            int diff = check-temp;

            ans+= (diff<0 ? 0 :diff);

        }

        return ans;

    }
};