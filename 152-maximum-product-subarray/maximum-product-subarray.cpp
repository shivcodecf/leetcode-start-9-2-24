class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int p=1,p1=1,maxi=INT_MIN;

        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
         p*=nums[i];

       

         maxi = max(maxi,p);

           if(p==0)
         {
            p=1;
         }

        }

         p=1;

        for(int i=n-1;i>=0;i--)
        { 

         p*=nums[i];

         
         maxi = max(maxi,p);

         if(p==0)
         {
            p=1;
         }
         
        }

         return maxi;

    }
};