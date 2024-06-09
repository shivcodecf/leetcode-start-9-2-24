class Solution {
public:
    int numberOfChild(int n, int k) {

        int x=-1,flag=0;

       for(int i=0;i<=k;i++)
       {  
          if(!flag)
          {
            x++;
          }
          else{
           x--;
          }
         
          if(x==n-1)
          {
           
            flag=1;
          }
          else if(x==0)
          {
           
            flag=0;
          }
       }

       return x;


    }
};