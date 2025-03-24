class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
           int j=0,cnt=0,ans=0,sum=0;
        
           for(int i=0;i<nums.size();i++)
           {


            if(nums[i] & 1)
            { 

                 cnt++;

                 sum=0;

                 if(cnt==k)
            {
                 

                while(cnt==k)
                {
                    

                    sum++;

                    if(nums[j] & 1)
                    {
                       cnt--;
                    }

                     j++;
                   
                    
                }

                ans+=sum;
            }


            }

            else{
               
                ans+=sum;
                
            }

           


           }

           return ans;

    }
};