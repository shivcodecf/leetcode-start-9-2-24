class Solution {
public:
    void reverseString(vector<char>& s) {
      int i=0,n=s.size(),j=n-1;

      while(i<j)
      {
        char ch= s[j];
        s[j]=s[i];

        s[i]=ch;
        i++;
        j--;

      }  
     
    }
};