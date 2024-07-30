class Solution {
public:
    int minimumDeletions(string s) {
       
        
        int a=0,b=0,mini=INT_MAX,ans=0;

        for(int i=0;i<s.size();i++)
        {
            
        if(s[i]=='a' && b>0)
        {
           b--;
          ans++;
          
        }
        else if(s[i]=='b')
        {
            b++;
        }


        }
        return ans;
    }
};