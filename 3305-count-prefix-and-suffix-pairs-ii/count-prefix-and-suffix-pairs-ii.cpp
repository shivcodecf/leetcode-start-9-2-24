struct Node {
public: 

    std::unordered_map<long long, Node*> child;

    long long cnt = 0;  // In-line initialization of cnt to 0

};

// Function to create a new Trie node
Node* getTrieNode() {

    Node* newNode = new Node();

    return newNode;

}

class Solution {
public:

    Node* root;  // Root node of the Trie

    Solution() {

        root = getTrieNode();  // Initialize the root node once

    }


    long long countPrefixSuffixPairs(vector<string>& words) {

        long long ans = 0;
        
        // Iterate through all words
        for (long long j = 0; j < words.size(); j++) {

            Node* node = root;  // Start from the root node
            long long n = words[j].size();
            
            // Insert the word into the Trie
            for (long long i = 0; i < n; i++) {

                long long val = words[j][i] * 128 + words[j][n - 1 - i];  // Hashing the character pair

                if (node->child.find(val) == node->child.end()) {

                    node->child[val] = getTrieNode();  // Create new node if it doesn't exist

                }

                node = node->child[val];  // Move to the next node

                ans += node->cnt;  // Accumulate the count of existing prefix-suffix pairs
            }

            node->cnt++;  // Increment the count for the current word

        }

        return ans;  // Return the total count of prefix-suffix pairs

    }

};
