class Solution {
public:
    long long maxProduct(vector<int>& nums) {

       
         int n = nums.size();


        for(int i=0;i<nums.size();i++)
        {
            nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin(),nums.end());


        

        int x = 100000;

        int y = -100000;


        return std::max(
    1LL * nums[n - 1] * nums[n - 2] * x,
    1LL * nums[n - 1] * nums[n - 2] * y
);



        


        

    }
};