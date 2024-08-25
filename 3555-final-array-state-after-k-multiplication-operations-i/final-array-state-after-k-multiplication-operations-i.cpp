#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        // Custom comparator
        auto comparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;  // Min-heap by index if priorities are equal
            }
            return a.first > b.first;  // Min-heap by priority
        };
        
        // Priority queue with custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);

        // Push initial pairs of (value, index) into the priority queue
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        // Process k operations
        while (k--) {
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();

            long long z = x * multiplier;

            pq.push({z, y});
        }

        // Collect the results in a vector of pairs (index, value)
        vector<pair<int, int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }

        // Sort the result by index to maintain the original order
        sort(ans.begin(), ans.end());

        // Extract the final values from the sorted pairs
        vector<int> res;
        for (const auto& p : ans) {
            res.push_back(p.second);
        }

        return res;
    }
};
