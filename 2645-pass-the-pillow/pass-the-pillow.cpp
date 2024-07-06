class Solution {
public:
    int passThePillow(int n, int time) {
        
        int start=1,t=0,flag=0;

        while(t<time)
        {
            t++;

            if(!flag)
            {
              start++;
              if(start==n)
              {
                flag=1;
              }
            }

            else {
                start--;
                if(start==1)
                {
                    flag=0;
                }
            }
           

        }

        return start;




    }
};