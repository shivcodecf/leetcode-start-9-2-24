class Solution {
     
     int solve(int mid,vector<int>& nums,int op)
     {
        int sum=0,c=0;

        for(int i=0;i<nums.size();i++)
        {  

            if(nums[i]>mid)
            {
                 sum+=(nums[i])/mid;

                 if(nums[i]%mid==0)
                 {
                    c++;
                 }

                 
            }
          
          
           
        }

        return (sum-c)<=op;

     }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int high = *max_element(nums.begin(),nums.end());

        int low =1,ans=INT_MAX;

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(solve(mid,nums,maxOperations))
            { 

                ans = min(ans,mid);

                high = mid-1;

            }  

            else{

                low = mid+1;
            }  

        } 

        return ans;  

    }
};