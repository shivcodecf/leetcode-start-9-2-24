class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int n=nums.size(),ans=0,even=0,odd=0,flag=0,check=0;

        for(int i=0;i<n;i++)
        {
            if(!(nums[i] & 1))
            {
                even++;
            }
        }

        ans=max(ans,even);

        for(int i=0;i<n;i++)
        {
            if((nums[i] & 1))
            {
                odd++;
            }
        }

           ans=max(odd,ans);

           check=0,even=0,odd=0;

         for(int i=0;i<n;i++)
        { 

            if((nums[i] & 1) && (!flag))
            {
              odd++;
              flag=1;
            }
            else if(!(nums[i] & 1) && (flag) )
            {
               even++;
               flag=0;
            }

        }

        int x= odd+even;flag=0,odd=0,even=0;

        if(x>=2)
        {
            ans=max(ans,x);
        }

         for(int i=0;i<n;i++)
        { 

            if((nums[i] & 1) && (flag))
            {
              odd++;
              flag=0;
            }
            else if(!(nums[i] & 1) && (!flag) )
            {
               even++;
               flag=1;
            }

        }

        x= even+odd;

        if(x>=2)
        {
          ans=max(ans,x);
        }


        return ans;









        








    }
};