class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        
        for(int i=0;i<n;i++)
        { 
            int c=0,c1=0;

          if((i-k)>=0 && (i-k)<n)
          { 
            c1++;
            if(nums[i-k]<nums[i])
            {
                c++;
            }
          }
           if((i+k)>=0 && (i+k)<n)
          { 
            c1++;
            if(nums[i+k]<nums[i])
            {
                c++;
            }
          }

          if(c==c1)
          {
            ans+=nums[i];
          }

          

          
        }

        return ans;
    }
};