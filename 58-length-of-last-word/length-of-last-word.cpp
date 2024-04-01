class Solution {
public:
    int lengthOfLastWord(string s) {

     string ans="";
     int n=s.size(),flag=0;
     for(int i=n-1;i>=0;i--)
     { 
        if(s[i]!=' '){
        ans+=s[i]; 
        flag=1;
        }

        else if(!flag && s[i]==' ') { 
            continue;
           
        }
        else {
            return ans.size();
        }
     }  
     return ans.size(); 

    }
};