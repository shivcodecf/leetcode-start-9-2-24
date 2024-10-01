class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        
        string s3 = s1;

        string s4 = s2;

           sort(s3.begin(),s3.end());

          reverse(s3.begin(),s3.end());

          sort(s4.begin(),s4.end());

           reverse(s4.begin(),s4.end());

            sort(s1.begin(),s1.end());

             sort(s2.begin(),s2.end());



        int flag = 0, flag1=0;

        int n=s1.size(),m=s2.size();

        if(n!=m)
        {
            return false;
        }


        for(int i=0;i<s3.size();i++)
        {
            if(s3[i]<s4[i])
            {
                flag = 1;
            }
        }

         

          for(int i=0;i<n;i++)
        {
            if(s3[i]>s4[i])
            {
                flag1 = 1;
            }
        }

        if(flag && flag1)
        {
            return false;
        }

        return true;



    }
};