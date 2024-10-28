class Solution {
public:
    long long lcm(long long a, long long b) { return (a / std::gcd(a, b)) * b; }


    long long maxScore(vector<int>& nums) {

        long long c = 0, ans = 0, res = 0;

        if(nums.size()==1)
        {  
                    

                       return nums[0]*nums[0];
        }

        

      

        for (int c = 0; c < nums.size(); c++) {
            long long gd = 0, lc = 1;  // Start lc at 1 for correct multiplication

            for (int j = 0; j < nums.size(); j++) {
                if (j != c) {
                    gd = __gcd((int)gd, (int)nums[j]);
                    lc = lcm(lc, nums[j]);
                }
            }

            ans = std::max(ans, gd * lc);
        }

        long long gd=0,lc=1;

            for(int i=0;i<nums.size();i++)
            {
                      gd = __gcd((int)gd, (int)nums[i]);
                      lc = lcm(lc, nums[i]);
                  
            }

         ans = max(ans,gd*lc);
        

        

        return ans;
    }
};