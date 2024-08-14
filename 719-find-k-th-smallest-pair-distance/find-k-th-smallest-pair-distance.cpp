class Solution {
public:
     
     bool solve(vector<int>& nums,int target)
     {    
           int mid=0;
           int n=nums.size();

           int low = 0, high = n-1;

           while(high>low)
           {
                mid = low + (high-low)/2;

              int diff = nums[high] - nums[low];

              if(diff==target)
              {
                return true;
              }

              if(diff>target)
              {
                high = mid-1;

              }
              else {
                low = mid +1;
              }


              
           }

           return false;

     }  

    int smallestDistancePair(vector<int>& nums, int k) {

       sort(nums.begin(),nums.end());

       vector<int>v;
       int n=nums.size();

       for(int i=0;i<n;i++)
       {
        for(int j=i+1;j<n;j++)
        {
            v.push_back(abs(nums[j]-nums[i]));
        }
       }

       nth_element(v.begin(),v.begin()+k-1,v.end());

       return v[k-1];

       
    }
};