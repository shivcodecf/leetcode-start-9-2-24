class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;

        int n = nums.size();

        vector<int> ans;

        // [1,3,-1,-3,5,3,6,7] -->

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i + 1 >= k) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};