class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // hold max reach of left -> its biggest right
        vector<int> maxReach(n+1, 0);
        
        for (int i = 0; i < ranges.size(); ++i) {
            int left = max(i - ranges[i], 0);
            int right = min(i + ranges[i], n);
            maxReach[left] = max(right,maxReach[left]);
        }

        int count = 0;  // number of taps needed
        int currEnd = 0; // furthest point we can reach with 'count' number of taps on
        int currFarthest = 0; // furtherst point we can reach 
        
        for (int i = 0; i <= n; ++i) {
            // we havent been able to reach i so there is a gap 
            if (i > currFarthest) {
                return -1; 
            }
            // we have to turn on another tap. we turn on the tap that gives us currFarthest
            if (i > currEnd) {
                ++count; // another tap
                currEnd = currFarthest; // we turned on tap with furthest reach
            }
            // we have now got to this tap
            currFarthest = max(currFarthest, maxReach[i]); // if this tap gives us a new max furthest

            

        }

        // if we could turn on reach all n taps
        return (currEnd == n) ? count : -1;
    }
};