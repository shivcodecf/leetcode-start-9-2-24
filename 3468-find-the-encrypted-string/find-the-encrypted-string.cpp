class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string ans="";
        string s1= s+s;
         
        for(int i=0;i<10000;i++)
        {
            s1+=s;
        }
        
        for(int i=0;i<s.size();i++)
        {   
           ans+=s1[i+k];
        }
        
        return ans;
    }
};