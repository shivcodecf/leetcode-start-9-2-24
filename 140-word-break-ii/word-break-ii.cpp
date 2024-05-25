class Solution {
public: 
    vector<string> ans;
    void rec(string &s, set<string> &dict, int ind, string ds){
        if(ind>=s.size()){
            ds.pop_back();
            ans.push_back(ds);
            return;
        }
        string word="";
        for(int i=ind;i<s.size();i++){
            word+= s[i];
            if(dict.find(word)!=dict.end()){
                rec(s,dict,i+1,ds+word+" ");
               
            }
        }
    }
    vector<string> wordBreak(string &s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        rec(s,dict,0,"");
        return ans;

    }
};