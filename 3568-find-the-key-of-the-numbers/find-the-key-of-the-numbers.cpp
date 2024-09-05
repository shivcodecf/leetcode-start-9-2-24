class Solution {
public:
    int generateKey(int num1, int num2, int num3) {


       string ans="";

      

       int maxi = max({num1,num2,num3});

       while(maxi>0)
       { 

         int r1= num1%10;
         int r2= num2%10;
         int r3= num3%10;

         int mini = min({r1,r2,r3});

         ans+=mini+'0';

         maxi = maxi/10;

         num1 = num1/10;

         num2 = num2/10;
         num3 = num3/10;



       }

       reverse(ans.begin(),ans.end());

       int res = stoi(ans);

       return res;










    }
};