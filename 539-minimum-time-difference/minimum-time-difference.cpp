class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
       int n = timePoints.size();
        
        // Convert each time point to minutes since 00:00
        vector<int> minutes;
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            int totalMinutes = hours * 60 + mins;
            minutes.push_back(totalMinutes);
        }
        
        // Sort the time points in ascending order
        sort(minutes.begin(), minutes.end());
        
        // Initialize the minimum difference to a large number
        int minDiff = INT_MAX;
        
        // Compare adjacent time points
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        int x = minutes[n-1] - minutes[0];

         x= min(x,1440-x);


       
        minDiff = min(minDiff,x);
        
        return minDiff;
        


    }
};