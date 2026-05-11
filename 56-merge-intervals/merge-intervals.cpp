class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<int> newIntervals;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        newIntervals.push_back(intervals[0][0]);

        newIntervals.push_back(intervals[0][1]);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            cout << intervals[i][0] << " " << intervals[i][1] << endl;
        }

        int i = 1;

        while (i < n) {

            if (intervals[i][0] > newIntervals[1]) {
                ans.push_back(newIntervals);
                newIntervals[0] = intervals[i][0];
                newIntervals[1] = intervals[i][1];
            }

            if (intervals[i][1] < newIntervals[0]) {

                ans.push_back(intervals[i]);
               

            } else {
                newIntervals[0] = min(newIntervals[0], intervals[i][0]);
                newIntervals[1] = max(newIntervals[1], intervals[i][1]);
            }

            i++;
        }

        ans.push_back(newIntervals);

        // while (i < n) {
        //     ans.push_back(intervals[i]);
        //     i++;
        // }

        return ans;
    }
};