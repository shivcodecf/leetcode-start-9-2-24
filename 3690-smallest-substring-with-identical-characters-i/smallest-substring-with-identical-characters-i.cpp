class Solution {

bool solve(int mid,string& s,int k)
{    
          bool flag=true;
    
          string s1 = s;

          int c=1,res=0,c1=0,check=0,check1=0;

          if(mid==1)
          { 

            for(int i=0;i<s1.size();i++)
            {
             c1++;
             if(c1%2 && s1[i]!='1')
             {
               check++;
             }
             else if(c1%2==0 && s1[i]!='0')
             {
                check++;
             }

            }

            c1=0;

            for(int i=0;i<s1.size();i++)
            {
             c1++;
             if(c1%2==0 && s1[i]!='1')
             {
               check1++;
             }
             else if(c1%2 && s1[i]!='0')
             {
                check1++;
             }

            }

            return check<=k || check1<=k;

          }


    
        

        for(int i=1;i<s1.size();i++)
        {
            if(s1[i]==s1[i-1])
            {
                c++;
            }
            else {
                res+=(c/(mid+1));
                c=1;
            }
            
        }

        res+=(c/(mid+1));

        cout <<res<<endl;

        return res<=k;

        

         

    

      

    

    

    
}

public:
    int minLength(string s, int numOps) {

           int low = 1,high = s.size(),ans=s.size();

         

            while(low<=high)
            {
                int mid = low+(high-low)/2;

                if(solve(mid,s,numOps))
                { 
                    ans = min(ans,mid);
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }

           return ans;
        
    }
};