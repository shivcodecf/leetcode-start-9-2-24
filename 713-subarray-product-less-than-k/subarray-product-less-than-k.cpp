class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=1,res=0,n=nums.size();
       
        int i=1,j=0;
        for(int i=0;i<nums.size();i++)
        {  
            ans*= nums[i];
            while(ans>=k && i>=j)
            {
                ans/= nums[j];
                j++;
            }
            res+= i-j+1;
        }

        return res;  
    }
};