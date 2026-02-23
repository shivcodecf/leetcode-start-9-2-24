class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        int n = nums.size();

        int x = 0, y = 0, c = 0, turn = 0;

        for (int i = 0; i < n; i++) {

            c++;

            if ((c % 6 == 0) || (nums[i] & 1)) {
               
               if(c%6==0)
               {
                turn++;
               }
                 if(nums[i] & 1)
               {
                turn++;
               }
                

                if (turn & 1) {
                    y += nums[i];
                } else {
                    x += nums[i];
                }

            }

            else {

                if (turn & 1) {
                    y += nums[i];
                } else {
                    x += nums[i];
                }
            }

        }

        // x = 2+4+2+1
        // y = 1+2

        return x-y;
    }
};