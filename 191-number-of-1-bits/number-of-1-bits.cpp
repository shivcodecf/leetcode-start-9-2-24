class Solution {
public:
    int hammingWeight(uint32_t n) {

     
      int ans=0;
    //   for(int i=0;i<s.size();i++)
    //   {
    //       if(s[i]=='1')
    //       {
    //           ans++;
    //       }
    //   }  

    while(n)
    {    
        if(1 & n)
       
         ans++;

         n=n>>1;

       
    }
      return ans;
    }
};