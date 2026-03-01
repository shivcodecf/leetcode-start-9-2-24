class Solution {
    vector<string> ans;

    void solve(int n, string& s, int count, int forw, int bac) {



        if (s.size() == n * 2) {
            ans.push_back(s);
            return;
        }

         if(forw<n)
        {  
             s+='(';
            solve(n,s,count,forw+1,bac);
             s.pop_back();
        }

        

        if(bac<forw)
        {
            
              s+=')';
            solve(n,s,count,forw,bac+1);
             s.pop_back();
        }

       


        // s.pop_back();

       


        
    }

public:
    vector<string> generateParenthesis(int n) {

        string s = "";

        solve(n, s, 0, 0, 0);

        return ans;
    }
};