class Solution { 
    private:

    int solve(vector<int>& nums,int i,int j)
    {
        if(i>j) return 0;
        if(i==j) return nums[i];

        int take1= nums[i] + min(solve(nums,i+2,j),solve(nums,i+1,j-1));

        int take2 = nums[j] + min(solve(nums,i+1,j-1),solve(nums,i,j-2));

        return max(take1,take2);


    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);

        
        int res1 = solve(nums,0,n-1);

        int res2 = sum-res1;

        if(res1>=res2)
        return true;
        return false;


        

    }
};