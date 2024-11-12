#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items, std::vector<int>& queries) {
        std::vector<std::pair<int, int>> v;
        for (const auto& item : items) {
            v.push_back({item[0], item[1]});
        }

        // Sort items by price
        std::sort(v.begin(), v.end());

        // Precompute maximum beauty up to each price
        std::vector<std::pair<int, int>> maxBeautyByPrice;
        int maxBeauty = -1;
        for (const auto& [price, beauty] : v) {
            maxBeauty = std::max(maxBeauty, beauty);
            maxBeautyByPrice.push_back({price, maxBeauty});
        }

        std::vector<int> ans;
        for (const int query : queries) {
            // Use upper_bound to find the first element with price > query
            auto it = std::upper_bound(maxBeautyByPrice.begin(), maxBeautyByPrice.end(), std::make_pair(query, INT_MAX));

            if (it == maxBeautyByPrice.begin()) {
                ans.push_back(0);  // No items affordable
            } else {
                --it;  // Go to the last affordable item within budget
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};
