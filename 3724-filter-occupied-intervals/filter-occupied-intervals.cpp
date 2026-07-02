class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        if (occupiedIntervals.empty())
            return {};

        // Step 1: Sort intervals
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step 2: Merge overlapping or touching intervals
        vector<vector<int>> merged;
        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];

        // [1,4], [2,3]

        // [1,1] , [2,2]  2<=2  end = 2
        // [1,2],[3,4] -- 3<=3

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            int currStart = occupiedIntervals[i][0];
            int currEnd = occupiedIntervals[i][1];

            // Overlap OR touching
            if (currStart <= end + 1) {
                end = max(end, currEnd);
                // end = 4
            } else {
                merged.push_back({start, end});
                start = currStart;
                end = currEnd;
            }
        }

        merged.push_back({start, end});

        // Step 3: Remove free interval
        vector<vector<int>> result;

        // [1,5]   [7,9]

        for (auto interval : merged) {
            int L = interval[0];
            int R = interval[1];

            // No overlap
            if (R < freeStart || L > freeEnd) {
                result.push_back({L, R});
                continue;
            }

            // Left remaining part
            if (L < freeStart) {
                result.push_back({L, freeStart - 1});
            }

            // Right remaining part
            if (R > freeEnd) {
                result.push_back({freeEnd + 1, R});
            }
        }

        return result;
    }
};