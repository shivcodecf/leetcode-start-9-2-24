class Solution {
public:
    long long sumAndMultiply(int n) {

         string s = "";

        int sum = 0,y = 0;

        

        while(n>0)
        { 

            int x = n%10;

            if(x>0)
            {
               s+=x+'0';
               y+=x*10;
            }
           
            sum+=x;

            n = n/10;

        }


        cout <<sum <<" "<<s<<endl;

        reverse(s.begin(),s.end());

        long long x;
         
         if(s!="")
        x = stoi(s);

        return sum*x;





        
    }
};