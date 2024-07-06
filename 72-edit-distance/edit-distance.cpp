class Solution {
public:
    int findMinOperations(string &word1, string &word2, int index1, int index2, vector<vector<int>> &memo) {
        // If we've reached the end of word1 or word2
        if (index1 >= word1.size() || index2 >= word2.size()) {
            if (index2 < word2.size()) return word2.size() - index2; // Remaining characters in word2 need to be inserted
            else if (index1 < word1.size()) return word1.size() - index1; // Remaining characters in word1 need to be deleted
            else return 0; // Both words are fully traversed
        }

        // If already calculated, return the stored result
        if (memo[index1][index2] != -1) return memo[index1][index2];

        // Initialize variables for possible operations
        int insertOp = INT_MAX, deleteOp = INT_MAX, replaceOp = INT_MAX, noOp = INT_MAX;

        // If characters match, no operation is needed, move to the next characters
        if (word1[index1] == word2[index2]) {
            noOp = findMinOperations(word1, word2, index1 + 1, index2 + 1, memo);
        } else {
            // Insert a character in word1
            insertOp = 1 + findMinOperations(word1, word2, index1, index2 + 1, memo);
            // Delete a character from word1
            deleteOp = 1 + findMinOperations(word1, word2, index1 + 1, index2, memo);
            // Replace a character in word1
            replaceOp = 1 + findMinOperations(word1, word2, index1 + 1, index2 + 1, memo);
        }

        // Store the result in memo table and return the minimum of the operations
        return memo[index1][index2] = min({noOp, insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        // If word1 is empty, return the length of word2
        if (word1.empty()) return word2.size();
        
        // Create a memoization table initialized with -1
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        
        // Call the recursive helper function
        return findMinOperations(word1, word2, 0, 0, memo);
    }
};