class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int p=1;

        int n=nums.size();

        map<int,int>mp;

        int z=0;

        for(int i=0;i<n;i++)
        {  
            if(nums[i]!=0)
            {
                p = p*nums[i];
            }
           

            if(nums[i]==0)
            { 
                z++;
              
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                if(z)
                {
                    ans.push_back(0);
                }
                else {
                    int x = p/nums[i];
                    ans.push_back(x);
                }
            }

            else {
              if(z>=2)
              {
                ans.push_back(0);
              }
              else {
                ans.push_back(p);
              }

            }
        }

        return ans;


    }
};