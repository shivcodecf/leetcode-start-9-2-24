int ans;

class Solution {
    void solve(string& s1, int idx, int& temp_ans, unordered_set<string>& seen) { 
        if (idx >= s1.size()) {
            ans = max(ans, temp_ans); // Update the answer if the current split is larger
            return;
        }

        for (int i = 1; i <= s1.size() - idx; i++) {
            string s2 = s1.substr(idx, i); // Generate substring
            
            if (seen.find(s2) == seen.end()) { 
                seen.insert(s2); 
                temp_ans++; 

              
                solve(s1, idx + i,  temp_ans, seen);

                
                temp_ans--;
                seen.erase(s2);
            }
        }
    }

public:
    int maxUniqueSplit(string s) {
         ans = 0;
        int temp_ans = 0;
        unordered_set<string> seen; // Use set for uniqueness check
        
        solve(s, 0, temp_ans, seen); // Start recursion
        
        return ans;
    }
};
