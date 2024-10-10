class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n=nums.size();

        stack<int>st;

        vector<int>pref;

        for(int i=n-1;i>=0;i--)
        {   

           if(pref.size()==0)
           {
            pref.push_back(i);
           }
           else {
            int ind=pref.back();
            if(nums[ind]<nums[i])
            {
                pref.push_back(i);
            }
           }


        }

        reverse(pref.begin(),pref.end());

       for(int i=0;i<pref.size();i++)
       {
         cout <<pref[i]<<" ";
       } 

      

          int m=pref.size(),ans=0;

         for(int i=0;i<n;i++)
         {
            int low = 0,high = m-1;

            while(low<=high)
            {
                int mid = low+(high-low)/2;
                     
                     int x = pref[mid];
              
                  if(nums[x]>=nums[i])
                {   
                    if(pref[mid]>i)
                    {
                       ans =  max(ans,pref[mid]-i);
                    }
                   
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
                

                
            }

         }

         return ans;

    
    }
};