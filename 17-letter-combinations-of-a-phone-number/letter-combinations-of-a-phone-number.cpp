class Solution {
   
   map<int,vector<char>>mp;

   vector<string>ans;

   void solve(string& digits,string& s,int x)
   { 

     if(x==digits.size())
     {
        ans.push_back(s);
        return;
     }

     int num = digits[x]-'0';

     for(auto it:mp[num])
     {
        s+=it;

        solve(digits,s,x+1);

        s.pop_back();
        
     }

    
   }

public:
    vector<string> letterCombinations(string digits) {

        mp[2].push_back('a');
        mp[2].push_back('b');
        mp[2].push_back('c');

        mp[3].push_back('d');
        mp[3].push_back('e');
        mp[3].push_back('f');

        mp[4].push_back('g');
        mp[4].push_back('h');
        mp[4].push_back('i');

        mp[5].push_back('j');
        mp[5].push_back('k');
        mp[5].push_back('l');

        mp[6].push_back('m');
        mp[6].push_back('n');
        mp[6].push_back('o');

        mp[7].push_back('p');
        mp[7].push_back('q');
        mp[7].push_back('r');
        mp[7].push_back('s');

        mp[8].push_back('t');
        mp[8].push_back('u');
        mp[8].push_back('v');

        mp[9].push_back('w');
        mp[9].push_back('x');
        mp[9].push_back('y');
        mp[9].push_back('z');

        string s="";




        solve(digits,s,0);

        return ans;
        
    }
};