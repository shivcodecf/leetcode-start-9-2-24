class Solution {
public:
    int numSteps(string s) {
     
     int carry=0,n=s.size(),ans=0;

     for(int i=n-1;i>0;i--)
     {
        int digit= s[i]-'0'+ carry;

        if(digit%2==0)
        {
          ans+=1;
        }
        else {
            ans+=2;
            carry=1;
        }

     }
     
     return ans+carry;



    }
};