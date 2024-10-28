#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Sort the input array
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> mp;
        int maxLength = 0;
        
        for (int num : nums) {
            // Check if there exists a previous element which is a square root of the current number
            int x = sqrt(num);

            if(mp.find(x)!=mp.end() && x*x==num)
            {
                mp[num] = mp[x]+1;
            }
            else {
                mp[num] = 1;
            }
            maxLength = max(maxLength,mp[num]);


        }

        return maxLength >= 2 ? maxLength : -1;
    }
};
