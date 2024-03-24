class Solution {
public:
    int minOperations(int k) {

       
       int n=1e+5,ans=0,check=1,mini=INT_MAX;

       int x=k/check;

       if(k%check)
       {
        x++;
       }
       ans+=x-1;
       
       mini=min(mini,ans);

       for(int i=2;i<=n;i++)
       {
          check++;
         x=k/check;
         if(k%check)
         {
            x++;
         }
          ans=x-1+(check-1);
          mini=min(mini,ans);

       }

       return mini;




    }
};