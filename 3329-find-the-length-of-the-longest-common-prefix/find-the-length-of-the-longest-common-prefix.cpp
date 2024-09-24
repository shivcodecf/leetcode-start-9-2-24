class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {


        map<string, int> vis; 

        for(int j=0;j<arr1.size();j++){

            string s = to_string(arr1[j]); string cc = ""; 
            for(int i = 0; i < s.size(); i++){

                cc += s[i]; vis[cc]++;
            }
        }


        int  ans = 0; 

        for(int j=0;j<arr2.size();j++){

            string s = to_string(arr2[j]); string cc = "";

            for(int i = 0; i < s.size(); i++){

                cc += s[i];

                 if(vis.find(cc)!=vis.end()) 
                 ans = max(ans, (i + 1)); 

            }
        }

        return ans; 


    }
};