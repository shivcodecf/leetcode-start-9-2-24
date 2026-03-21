class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        vector<int>pref(n);

        pref[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            pref[i] = pref[i-1]+nums[i];
        }

        int low = 0, high = n - 1;

        // [2,5,6,8,12,15]

        int ans = INT_MAX;


        for(int i=0;i<n;i++)
        {
            if(pref[i]>=target)
            {
             ans = min(ans,i+1);
            }
        }


        for(int i=0;i<n;i++)
        { 

            int low = i;
            int high = n-1;

            while(low<=high)
            {
                int mid = low+(high-low)/2;

                int check = pref[mid]-pref[i];

                if(check>=target)
                {
                    ans =  min(ans,mid-i);
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }

                
            }

        }

        return ans == INT_MAX ? 0 : ans;

       
    }
};