class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int, int>> v,v1;
        int n = pairs.size();

        // Convert pairs from vector of vectors to vector of pairs
        for(int i = 0; i < pairs.size(); i++) {
            v.push_back({pairs[i][0], pairs[i][1]});
             v1.push_back({pairs[i][0], pairs[i][1]});
        }

        // Lambda function for custom sorting
        auto customComparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // Sort by second element if first elements are equal
            }
            return a.first < b.first; // Otherwise, sort by first element
        };


       auto customComparator1 = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; // Sort by first element if second elements are equal
            }
            return a.second < b.second; // Otherwise, sort by second element
        };



        // Sort the vector of pairs
         sort(v.begin(), v.end(), customComparator);
         sort(v1.begin(), v1.end(), customComparator1);

        int x = v[0].second, ans = 1; // Initialize ans to 1 because we count the first pair

        // Find the longest chain
        for(int i = 1; i < n; i++) {
            if(v[i].first > x) { 
                ans++;
                x = v[i].second;
            }
        }

        x= v1[0].second;
        int ans1=1;

         for(int i = 1; i < n; i++) {
            if(v1[i].first > x) { 
                ans1++;
                x = v1[i].second;
            }
        }

        return max(ans,ans1);
    }
};
