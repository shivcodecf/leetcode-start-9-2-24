class Solution {
public:
    vector<vector<int>>subset;
    void helper(int index, vector<int>&current,vector<int>&nums)
    {
       if(nums.size()==index)
       {
        subset.push_back(current);
        return;
       }
       current.push_back(nums[index]);
       helper(index+1,current,nums);

       current.pop_back();

       helper(index+1,current,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        helper(0,current,nums);
        return subset; //return answer
    }
};