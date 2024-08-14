class Solution {
public:
     
   

    int smallestDistancePair(vector<int>& nums, int k) {

       sort(nums.begin(),nums.end());

       int n=nums.size();

       int diff = nums[n-1] - nums[0];

       int m = n*(n-1)/2;

        vector<int>v(diff+1,0);

       for(int i=0;i<n;i++)
       { 

        for(int j=i+1;j<n;j++)
        {  
            int d = abs(nums[j]-nums[i]);

             v[d]++;
        }

       }


       for(int i=0;i<v.size();i++)
       {
         k-=v[i];

         if(k<=0)
         {
            return i;
         }
       }

       return -1;













       

       
    }
};