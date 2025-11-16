class Solution {
public:
    int minLengthAfterRemovals(string s) {

      int c1 =0,c2=0;

      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='a')
        {
            c1++;
        }else {
            c2++;
        }
      }  

      int left = abs(c1-c2);

      if(left==0)
      {
        return 0;
      }

      char ch;

      if(c1>c2)
      {
        ch = 'a';
      }
      else if(c2>c1)
      {
        ch = 'b';
      }

      int cnt = 0,ans =INT_MAX;

      for(int i=0;i<s.size();i++)
      {
        if(ch == s[i])
        {
            cnt++;
        }

        if(cnt == left)
        {
            break;
        }
      }

      ans = min(ans,cnt);

      cout <<ch<<endl;

      cnt=0;


        for(int i=s.size()-1;i>=0;i--)
      {
        if(ch == s[i])
        {
            cnt++;
        }

        if(cnt == left)
        {
            break;
        }
      }

       ans = min(ans,cnt);

       return ans;



      


        
    }
};