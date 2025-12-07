class Solution {
         
         bool isPrime(string& s1)
         {
            int num = stoi(s1);

            if(num == 1)
            {
                return false;
            }

            int check = 0;

            for(int i=2;i*i<=num;i++)
            {
                if(num%i==0)
                {
                    return false;
                }
            
            }


            return true;

         }


public:
    bool completePrime(int num) {

        string s = to_string(num);

        if(num==1)
        {
            return false;
        }

        
         string s1= "";

        for(int i=0;i<s.size();i++)
        {
            s1+=s[i];

            if(!isPrime(s1))
            {
               return false;
            }

        }


         reverse(s.begin(),s.end());

         s1= "";

         for(int i=0;i<s.size();i++)
        {
            s1+=s[i];
            string s2 = s1;

            reverse(s1.begin(),s1.end());


            if(!isPrime(s1))
            {
               return false;
            }

            
            s1 = s2;
        }

        return true;




        
    }
};