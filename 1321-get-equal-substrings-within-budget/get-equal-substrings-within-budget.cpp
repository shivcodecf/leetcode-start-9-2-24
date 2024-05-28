#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int equalSubstring(string s, string t, int maxCost) {
        
     
     vector<int>v,pref(s.size());

     for(int i=0;i<s.size();i++)
     {
        int x=abs((s[i]-'a') - (t[i]-'a'));
        v.push_back(x);

     }

    
     pref[0]=0;
     pref[1]=v[0];

     for(int i=2;i<s.size();i++)
     {
        pref[i]=pref[i-1]+v[i];
     } 
         int start = 0;
        int current_cost = 0;
        int max_length = 0;
        int n=s.size();

       for(int end = 0; end < n; ++end) {

            current_cost += v[end];

            while (current_cost > maxCost) {
                current_cost -= v[start];
                ++start;
            }

            max_length = max(max_length, end - start + 1);

        }

        
    


    


     


     
     return max_length;

     
      


    }
};