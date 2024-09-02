#define ll unsigned long long

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {


        ll n = chalk.size();

        ll sum = 0;

        for(int i=0;i<n;i++)
        {
           sum+=(chalk[i])%1000000007;
          

           

           
        }

        // cout <<sum<<endl;

        


        // if(sum%k==0)
        // { 

        //     return 0;

        // }

        // ll temp = k;

        // if(sum>k)
        // {

        //    for(int i=0;i<n;i++)
        //    {
        //       if(temp>=chalk[i])
        //       {
        //         temp = temp - chalk[i];
        //       }
        //       else {
        //         return i;
        //       }
        //    } 

        // } 

      
        ll check = k;

        check = check % sum;

        ll div = k/sum;

        ll sum1 = div*sum;

        ll temp1 = k - sum1;

        // if(rem==0)
        // {
        //     return 0;
        // }

       



        //    ll temp = rem;

        //   cout <<temp<<endl;

        for(int i=0;i<n;i++)
        {
           if(check>=chalk[i])
           {
            check = check - chalk[i];
           }
           else {
            return i;
           }

        }

        return -1;




    }
};