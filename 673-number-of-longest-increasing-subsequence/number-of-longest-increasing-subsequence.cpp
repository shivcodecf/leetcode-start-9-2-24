class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        
        vector<int>t(n,1),c(n,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                  if(t[j]+1>t[i])
                  {
                    t[i] = t[j] + 1;
                    c[i] = c[j];
                    
                  }
                  else if(t[j]+1 == t[i])
                  {
                    c[i]+=c[j];
                  }
                  
                 
                }
                
            }
        }

        int maxi=1,ans=0;

        for(int i=0;i<t.size();i++)
        {  
          

            maxi = max(maxi,t[i]);


        }

        for(int i=0;i<t.size();i++)
        {
            cout <<t[i]<<" ";
        }

         cout <<endl;

         for(int i=0;i<t.size();i++)
        {
            cout <<c[i]<<" ";
        }

        cout <<endl;



        for(int i=0;i<t.size();i++)
        {
            if(t[i]==maxi)
            {
                ans+=c[i];
            }
        }


        return ans;
    }
};