class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
    vector<int> diff(n + 1, 0);

    // Range updates
    for (int i = 0; i < n; i++) {
        if (lights[i] > 0) {
            int left = max(0, i - lights[i]);
            int right = min(n - 1, i + lights[i]);

            diff[left]++;

            if (right + 1 < n)
                diff[right + 1]--;
        }
    }

    int ans = 0;
    int coverage = 0;
    int invisibleLen = 0;

    for (int i = 0; i < n; i++) {
        coverage += diff[i];

        if (coverage == 0) {
            invisibleLen++;
        } else {
            ans += (invisibleLen + 2) / 3;
            invisibleLen = 0;
        }
    }

    ans += (invisibleLen + 2) / 3;

    return ans;
    }
};                           