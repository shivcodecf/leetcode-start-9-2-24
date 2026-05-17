class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size();

        vector<int> left(n + 1, 1), right(n + 1, 1);

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << left[i] << " ";
        }

        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << right[i] << " ";
        }

        cout << endl;

        int ans = 0;

        for (int i = 1; i < n - 1; i++) {

            int l = left[i];
            int r = right[i];

            if (l > 1 && r > 1) {
                ans = max(ans, l + r - 1);
            }
        }

        return ans;
    }
};