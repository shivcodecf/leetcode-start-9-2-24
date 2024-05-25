class Solution {
public:
    vector<int> queryResults(int k, vector<vector<int>>& qr) {
        int n = qr.size();
        map<int,int> mp, clr;
        vector<int> res;
        
        for(auto &z: qr){
            int b = z[0];
            int c = z[1];
            if(mp.find(b) != mp.end()){
                clr[mp[b]]--;
                if(clr[mp[b]] == 0){
                    clr.erase(mp[b]);
                }
            }
            mp[b] = c;
            clr[c]++;
            res.push_back(clr.size());
        }
        
        return res;
    }
};