#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int maxi = INT_MIN;

        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++) {

            maxi = max(maxi, nums[i]);

        }

        int size = maxi + k + 2;



        vector<int> freq(size, 0);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

   

       

        int res = 1;

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int left = max(nums[i] - k, 0);

            int right = nums[i] + k + 1;

            mp[left]++;

            mp[right]--;
        }

        int over = 0;

        for (int i = 0; i < size; i++) {

            over += mp[i];

            int left = over - (freq[i]);

            if (left <= numOperations) {
                res = max(res, over);
            }
            else {
                res = max(res,numOperations+freq[i]);
            }

        }

        return res;
    }
};
