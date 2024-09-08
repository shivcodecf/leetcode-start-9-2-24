int dp[500][500];
int dp1[500][500];

class Solution { 
     
     int solve1(vector<int>& slices, int slice, int end, int ind) { 
        if (ind > end || slice <= 0) return 0;

        if (dp1[slice][ind] != -1) return dp1[slice][ind];

        int pick = slices[ind] + solve1(slices, slice-1, end, ind+2);

        int notpick = solve1(slices, slice, end, ind+1);

        return dp1[slice][ind] = max(pick, notpick);
     }
     
     
     int solve(vector<int>& slices, int slice, int end, int ind) {
        if (ind > end || slice <= 0) return 0;

        if (dp[slice][ind] != -1) return dp[slice][ind];

        int pick = slices[ind] + solve(slices, slice-1, end, ind+2);

        int notpick = solve(slices, slice, end, ind+1);

        return dp[slice][ind] = max(pick, notpick);
     }

public:
    int maxSizeSlices(vector<int>& slices) {
        
        memset(dp, -1, sizeof(dp));
        memset(dp1, -1, sizeof(dp1));

        int sliceCount = slices.size() / 3;
        int n = slices.size();

        // Case 1: We consider slices from 0 to n-2 (excluding last slice)
        int case1 = solve(slices, sliceCount, n-2, 0);

        // Case 2: We consider slices from 1 to n-1 (excluding first slice)
        int case2 = solve1(slices, sliceCount, n-1, 1);

        // Return the maximum of both cases
        return max(case1, case2);
    }
};
