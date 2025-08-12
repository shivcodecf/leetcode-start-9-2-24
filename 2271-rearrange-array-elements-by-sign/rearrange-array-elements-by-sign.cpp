class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int>v1,v2;
        

        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]<0)
           {
            v1.push_back(nums[i]);
           }
           else {
            v2.push_back(nums[i]);
           }
        }

        vector<int>ans(nums.size());

        int j=0,k=0;


        for(int i=0;i<nums.size();i++)
        {
            if(i%2)
            {
                ans[i] = v1[j++];
            }
            else {
                ans[i] = v2[k++];
            }
        }

        return ans;

    }
};