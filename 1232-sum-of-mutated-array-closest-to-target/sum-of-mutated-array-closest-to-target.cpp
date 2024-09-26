class Solution {

    long long solve(const vector<int>& arr, long long mid) {
        long long res = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= mid) {
                res += mid;
            } else {
                res += arr[i];
            }
        }
        return res;
    }

public:
    int findBestValue(vector<int>& arr, int target) {
        long long low = 0;
        long long high = *max_element(arr.begin(), arr.end()); // Should be the maximum in the array, not the target
        long long ans = INT_MAX, res = INT_MAX;

        while (low <= high) {


            long long mid = low + (high - low) / 2;
            long long call = solve(arr, mid);
            long long diff = abs(call - target); 

            if (diff < res || (diff == res && mid < ans)) {

                ans = mid;
                res = diff;
                
            }

            if (call < target) {

                low = mid + 1;

            } else {

                high = mid - 1;

            }


        }

        return ans;
    }
};
