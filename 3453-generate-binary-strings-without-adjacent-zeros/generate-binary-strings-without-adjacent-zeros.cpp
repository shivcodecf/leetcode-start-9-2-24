class Solution {
public:  

        void solve(int n,string s, vector<string>& v,int cnt,int flag)
        {
            if(cnt==n)
            {
                v.push_back(s);
                return;
            }
            if(flag==1)
            {
                solve(n,s+"1",v,cnt+1,0);
            }
            else {
               solve(n,s+"0",v,cnt+1,1);
                solve(n,s+"1",v,cnt+1,0);
            }

           



            
        }
    vector<string> validStrings(int n) {
        
        string s="";
        vector<string>v;
        solve(n,s,v,0,0);
        return v;

        
        
        
    }
};