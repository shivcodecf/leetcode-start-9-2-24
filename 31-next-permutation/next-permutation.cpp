class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int check = 0;

        for (int i = n - 1; i >= 1; i--) {

            if (nums[i - 1] < nums[i]) {

                int mini = INT_MIN;

                 check = 1;

                int idx = -1;

                for (int j = i; j < n; j++) {

                    if (nums[j] > nums[i-1]) {

                        mini = min(nums[j], mini);
                      
                        idx = j;

                        // break;
                       
                    }
                }

                swap(nums[i - 1], nums[idx]);
                reverse(nums.begin() + i, nums.end());
                cout << i-1<< " " <<idx<<endl;
                break;
            }
        }

        if (check==0) {
            reverse(nums.begin(), nums.end());
        }

        // return nums;
    }
};