class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size(),check=0;

        for(int i=n-1;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {  
                int mini = nums[i-1],indx=-1;
                check=1;

                for(int j=i;j<n;j++)
                {
                   if(nums[j]>mini)
                   {
                    
                     mini = min(mini,nums[j]);
                     indx = j;

                   }
                }

                if(indx!=-1)
                {
                    swap(nums[i-1],nums[indx]);
                }
                
                reverse(nums.begin()+i,nums.end());

                break;


            }


        }

        if(check==0)
        {
            reverse(nums.begin(),nums.end());
        }

        // return nums;


        
    }
};