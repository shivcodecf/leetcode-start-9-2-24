class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts(n);  // Store (start, index) pairs
        vector<int> ans(n, -1);            // Initialize the answer array with -1
        
        // Prepare the intervals sorted by start times
        for (int i = 0; i < n; ++i) {
            starts[i] = {intervals[i][0], i};
        }
        
        // Sort the intervals based on start times
        sort(starts.begin(), starts.end());
        
        // For each interval, find the minimum start that is >= end using binary search
        for (int i = 0; i < n; ++i) {

            int end = intervals[i][1];
            int low = 0, high = n - 1;
            int bestIdx = -1;
            
            // Binary search to find the smallest start >= end
            while (low <= high) {


                int mid = low + (high - low) / 2;
                if (starts[mid].first >= end) {
                    bestIdx = starts[mid].second;  // Store the index of the valid interval
                    high = mid - 1;  // Try to find a smaller start
                } else {
                    low = mid + 1;
                }

                
            }
            
            ans[i] = bestIdx;  // Store the index of the right interval, or -1 if not found
        }
        
        return ans;
    }
};
