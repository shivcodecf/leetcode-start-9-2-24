class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<int> pq;

        int n = nums.size();

        int i = 0, j = k - 1;

        map<int, int> mp;

        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
            mp[nums[i]]++;
        }

        vector<int> ans;

        ans.push_back(pq.top());

        while (i < n && j < n) {

            mp[nums[i]]--;

            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }

            i++;

            j++;

            if (j < n) {

                mp[nums[j]]++;
                pq.push(nums[j]);
               
            }
            else {
                break;
            }

            while (pq.size()) {
                int t = pq.top();
                if (mp[t] > 0) {
                    ans.push_back(t);
                    break;
                } else {
                    pq.pop();
                }
            }
        }

        return ans;
    }
};