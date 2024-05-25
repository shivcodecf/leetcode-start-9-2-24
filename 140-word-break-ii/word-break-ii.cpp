class Solution {
public: 
    vector<string> ans;
    void rec(string &s, set<string> &dict, int ind, string ds){
        if(ind>=s.size()){
            ds.pop_back();
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string word = s.substr(ind,i-ind+1);
            if(dict.find(word)!=dict.end()){
                rec(s,dict,i+1,ds+word+" ");
                word.pop_back();
            }
        }
    }
    vector<string> wordBreak(string &s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        rec(s,dict,0,"");
        return ans;
    }
};