class Solution {
    private:

    bool solve(vector<int>& nums,int mid)
    {  
         if(nums[0]>mid)  return false;

         long long buffer = nums[0];

       for(int i=1;i<nums.size();i++)
       { 
          

         


        

           long long  dif = mid - buffer;

           buffer = nums[i] - dif;

           if(buffer>mid) return false;
           

         


       }

       return true;

    }

public:
    int minimizeArrayValue(vector<int>& nums) {
        
        
        int n = nums.size();
        int maxi=-1,mini= INT_MAX;

        for(int i=0;i<n;i++)
        {
           maxi=max(maxi,nums[i]);
           mini=min(mini,nums[i]);
        }

        long long low = 0, high = maxi,mid=0,ans=maxi;

        while(high>=low)
        { 

           mid = low+(high-low)/2;

           if(solve(nums,mid))
           {  
              ans= mid;
              high = mid-1;

           }
           else {
              low = mid+1;
           }


        }

        return ans;


    }
};