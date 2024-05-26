#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   string compressedString(string word) {
    string ans = "";
    int n = word.size();
    
    for (int i = 0; i < n;) { 
        char currentChar = word[i];
        int count = 0;
        
        // Count occurrences of the current character
        while (i < n && word[i] == currentChar && count < 9) {
            count++;
            i++;
        }
        
        // Append the count and character to the result string
        ans += to_string(count) + currentChar;
    }

    return ans;
}
};