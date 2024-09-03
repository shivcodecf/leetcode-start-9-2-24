class Solution {
public:
    int getLucky(string s, int k) {

         int sum=0;

         string s1="";
        
        for(int i=0;i<s.size();i++)
        { 

           int check = s[i]-'a'+1;

           s1+=to_string(check);

        }

        for(int i=0;i<s1.size();i++)
        {
            sum+=(s1[i])-'0';
        }

        if(k==1)
        {
            return sum;
        }

        cout <<sum<<endl;

        
         for(int i=0;i<k-1;i++)
        {    
                     

              int x = sum,ans=0;

            

            

            while(x>0)
            {
                int y = x%10;
                ans+=y;
                x=x/10;


            }

            

              sum = ans;

        }


        return sum;

       

        


    }
};