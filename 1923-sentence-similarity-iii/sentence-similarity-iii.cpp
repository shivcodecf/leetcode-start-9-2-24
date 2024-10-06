class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split sentence1 into words
        vector<string> v1, v2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;
        
        // Parse sentence1
        while (ss1 >> word) {
            v1.push_back(word);
        }
        
        // Parse sentence2
        while (ss2 >> word) {
            v2.push_back(word);
        }
        
        // If v1 is shorter, swap them to always compare the shorter sentence with the longer one
        if (v1.size() < v2.size()) {
            swap(v1, v2);
        }
        
        int n = v1.size(), m = v2.size();
        int i = 0, j = 0;
        
        // Compare from the start
        while (i < m && v1[i] == v2[i]) {
            i++;
        }
        
        // Compare from the end
        while (j < m && v1[n - j - 1] == v2[m - j - 1]) {
            j++;
        }
        
        // The sentences are similar if the total matches cover the entire smaller sentence
        return (i + j >= m);
    }
};
