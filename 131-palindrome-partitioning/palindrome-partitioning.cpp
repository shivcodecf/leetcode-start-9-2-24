class Solution {

    

public:  
      vector<vector<string>> ans;  // Global variable to store the final result
      string s1="";

bool pal( string& s2) { 
    int i = 0, j = s2.size() - 1;
    while (i < j) {
        if (s2[i] != s2[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(string& s, int ind, vector<string>& v1) { 
    if (s.size() == ind) {
        ans.push_back(v1);
        return;
    }

    for (int i = ind; i < s.size(); i++) {  
         string s1 = s.substr(ind, i - ind + 1);  // Extract the substring
        if (pal(s1)) {   
            v1.push_back(s1);  // Add the palindrome substring to the current partition
            solve(s, i + 1, v1);  // Recur for the next part of the string
            v1.pop_back();  // Backtrack
        }
    }
}

vector<vector<string>> partition(string s) {
    ans.clear();  // Clear the global result before starting
    vector<string> v1;
    
    solve(s, 0, v1);
    return ans;
}
};