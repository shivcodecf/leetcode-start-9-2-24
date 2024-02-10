class Solution {
public: 

  bool check(string& s1)
  {
      int i=0,j=s1.size()-1;

      while(i<j)
      {
          if(s1[i]!=s1[j])
          {
              return false;
          }
          i++;
          j--;
      }
      return true;
  }

    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        
    
    for(int i=0;i<n;i++)
    {   
        int c=0;
        for(int j=i;j<n;j++)
        {    
            c++;   
            string s1=s.substr(i,c);

            if(check(s1))
            {
                ans++;
            }
        }
    }
    return ans;

    }
};