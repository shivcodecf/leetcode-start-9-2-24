class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        // [1,2,3,4,5,6,7,8]

        // []

        sort(points.begin(), points.end());

        int n = points.size();

        int prevMin = points[0][0];

        int prevMax = points[0][1];

        int ans = 1;

        for (int i = 1; i < n; i++) {

            if (prevMin <= points[i][0] && prevMax >= points[i][0]) {
                prevMin = min(prevMin, points[i][0]);
                prevMax = min(prevMax, points[i][1]);

            } else {
                ans++;
                prevMin = points[i][0];
                prevMax = points[i][1];
            }
        }

        return ans;
    }
};