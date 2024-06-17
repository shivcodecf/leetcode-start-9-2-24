class Solution {
public:
    bool judgeSquareSum(long long c) {
       long long x= 0;
       long long y= sqrt(c);
       while(x<=y)
       {
           long long res= pow(x,2)+pow(y,2);
           if(res==c)
           {
               return true;
           }
           else if(res>c)
           {
               y--;
           }
           else {
               x++;
           }
       } 
       return false;
    }
};