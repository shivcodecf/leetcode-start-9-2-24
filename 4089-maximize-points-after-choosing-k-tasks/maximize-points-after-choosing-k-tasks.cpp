class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {

        int n = technique1.size();
        long long ans = 0;

        vector<pair<int,int>> diff;  
        diff.reserve(n);

        // initial answer and diff array
        for(int i = 0; i < n; i++){
            ans += technique1[i];
            diff.push_back({technique2[i] - technique1[i], i});
        }

        // sort diffs descending
        sort(diff.begin(), diff.end(), greater<>());

        int allowed = n - k;

        for(int i = 0; i < allowed; i++){
            if(diff[i].first > 0){
                int idx = diff[i].second;
                ans -= technique1[idx];
                ans += technique2[idx];
            }
            else break; // No need to continue
        }

        return ans;
    }
};
