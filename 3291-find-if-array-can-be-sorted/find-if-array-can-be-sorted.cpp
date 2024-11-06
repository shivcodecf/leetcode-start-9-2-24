class Solution {
public:
    bool canSortArray(vector<int>& nums) {

        int ans = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            bool flag=false;

            for (int j = 0; j < nums.size() - i - 1;j ++) {

                if (nums[j + 1] < nums[j]) {

                     flag = true;

                    int count = __builtin_popcount(nums[j]);
                      
                    int count1 = __builtin_popcount(nums[j + 1]);

                    if (count == count1) {
                        swap(nums[j], nums[j + 1]);
                    }
                    else {
                        return false;
                    }
                   
                }
            }

         
        }

        return true;
    }
};