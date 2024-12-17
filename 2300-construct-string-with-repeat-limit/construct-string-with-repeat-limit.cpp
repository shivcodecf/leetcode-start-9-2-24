#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        // Step 1: Count character frequencies
        map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

      
        priority_queue<pair<char, int>> pq;
        for (auto it : freq) {
            pq.push({it.first, it.second});
        }

        string result = "";
        
        while (!pq.empty()) {
          
            auto top = pq.top();
            pq.pop();
            char currentChar = top.first;
            int currentCount = top.second;

           
            int appendCount = min(limit, currentCount);
            
            for (int i = 0; i < appendCount; i++) {
                result += currentChar;
            }

          
            currentCount -= appendCount;

            if (currentCount > 0) {
             
                if (pq.empty()) {
                    break;
                }

              
                auto nextTop = pq.top();
                pq.pop();
                char nextChar = nextTop.first;
                int nextCount = nextTop.second;

              
                result += nextChar;
                nextCount--;

               
                if (nextCount > 0) {
                    pq.push({nextChar, nextCount});
                }

                pq.push({currentChar, currentCount});
            }
        }

        return result;
    }
};
