class Solution {
    void solve(string& s1, int idx, int& ans, int& temp_ans, unordered_set<string>& seen) { 

        if (idx >= s1.size()) {
            ans = max(ans, temp_ans); // Update the answer if the current split is larger
            return;
        }


        for (int i = 1; i <= s1.size() - idx; i++) {
            string s2 = s1.substr(idx, i); // Generate substring
            
            if (seen.find(s2) == seen.end()) { // Check if it's a unique substring
                seen.insert(s2); // Mark it as seen
                temp_ans++; // Increment the count of unique substrings

                // Recur for the next part of the string
                solve(s1, idx + i, ans, temp_ans, seen);

                // Backtrack: undo changes
                temp_ans--;
                seen.erase(s2);
            }
        }
    }

public:
    int maxUniqueSplit(string s) {

        int ans = 0;
        int temp_ans = 0;
        unordered_set<string> seen; // Use set for uniqueness check
        
        solve(s, 0, ans, temp_ans, seen); // Start recursion
        
        return ans;
        
    }
};
