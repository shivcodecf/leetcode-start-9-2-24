class Solution {
    vector<vector<int>> tree;

    long long dfs(int node, vector<int>& baseTime) {

        // Leaf node
        if (tree[node].empty())
            return baseTime[node];

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        // Compute finish time of all children
        for (int child : tree[node]) {
            long long finishTime = dfs(child, baseTime);

            earliest = min(earliest, finishTime);
            latest = max(latest, finishTime);
        }

        long long ownDuration = (latest - earliest) + baseTime[node];

        return latest + ownDuration;
    }

public:
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {

        tree.assign(n, {});

        // Build rooted tree directly
        for (auto &e : edges) {
            int parent = e[0];
            int child = e[1];
            tree[parent].push_back(child);
        }

        return dfs(0, baseTime);
    }
};