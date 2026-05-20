class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;

        vector<int> newIntervals;

        newIntervals.push_back(intervals[0][0]);

        newIntervals.push_back(intervals[0][1]);

        // new = [2,8] , intervals =  [10,15]  

        // intervals = [10,15] , newIntervals = [20,30]


        for (int i = 1; i < n; i++) {

            if (newIntervals[1] < intervals[i][0]) {
                ans.push_back(newIntervals);
                newIntervals[0] = intervals[i][0];
                newIntervals[1] = intervals[i][1];
            } else if (newIntervals[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
            } else {
                newIntervals[0] = min(newIntervals[0], intervals[i][0]);
                newIntervals[1] = max(newIntervals[1], intervals[i][1]);
            }
        }

        ans.push_back(newIntervals);



        return ans;
    }
};