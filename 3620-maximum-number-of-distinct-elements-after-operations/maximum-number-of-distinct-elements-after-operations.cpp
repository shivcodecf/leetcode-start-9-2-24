class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        map<int,int>mp;

        int check =0,ans=0,flag=0;
        
        for(int i=0;i<nums.size();i++)
        { 

            int x = nums[i]-k;

            int y = nums[i]+k;

            if(i==0)
            {
             check = x+1;
             ans++;
            }
            else {
               if((check)>y)
               {
                flag=1;
               }
               else {

                ans++;

                check = max(check+1,x+1);

               }
            }

            
        }

        return ans;

    }
};