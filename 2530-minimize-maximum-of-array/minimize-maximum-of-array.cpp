class Solution {
    private:

    bool solve(vector<int>& nums,int mid)
    {  
         
         int m= nums.size();

         vector<long long>v(nums.begin(),nums.end());

       for(int i=0;i<m-1;i++)
       { 
          

        if(v[i]>mid) return false;

        long long buffer = mid-v[i];

        v[i+1] = v[i+1] - buffer;



        
   
           

         


       }


       return v[m-1]<=mid;

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