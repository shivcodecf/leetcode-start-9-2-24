#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Node {
public: 
    std::unordered_map<long long, Node*> child;  // Maps a hashed value to child nodes
    long long cnt = 0;  // In-line initialization of cnt to 0
};

// Function to create a new Trie node
Node* getTrieNode() {
    return new Node();  // Create and return a new Node
}

class Solution {
public:
    Node* root;  // Root node of the Trie

    // Constructor to initialize the root node
    Solution() {
        root = getTrieNode();  // Initialize the root node once
    }

    // Function to count prefix-suffix pairs
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;  // Initialize the result to 0
        
        // Iterate through all words
        for (long long j = 0; j < words.size(); j++) {
            Node* node = root;  // Start from the root node
            long long n = words[j].size();
            
            // Insert the word into the Trie
            for (long long i = 0; i < n; i++) {
                // Hashing the character pair
                long long val = words[j][i] * 128 + words[j][n - 1 - i];  

                // Check if the child node for this value exists
                if (node->child.find(val) == node->child.end()) {
                    node->child[val] = getTrieNode();  // Create new node if it doesn't exist
                }

                node = node->child[val];  // Move to the next node
                
                // Accumulate the count of existing prefix-suffix pairs at the current node
                ans += node->cnt;  
            }

            // Increment the count for the current word at the end of insertion
            node->cnt++;  
        }

        return ans;  // Return the total count of prefix-suffix pairs
    }
};
