class Solution {
public:
    vector<vector<int>>subset;
    void helper(int index, vector<int>&current,vector<int>&nums)
    {
        subset.push_back(current); // push the current subset into the resultant array
        for(int i=index;i<nums.size();i++)
        {
            current.push_back(nums[i]); // add the current element to consider the subsets corresponding to it
            helper(i+1,current,nums);  //generate subsets for this array
            current.pop_back(); // as this has been used, pop it
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        helper(0,current,nums);
        return subset; //return answer
    }
};