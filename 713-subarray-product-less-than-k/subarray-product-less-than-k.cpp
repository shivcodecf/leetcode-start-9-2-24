class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=1,res=0,n=nums.size();
       
        int i=0,j=0; 
        while(i<n && j<n)
        {     
            
            ans*=nums[i];
            while(ans>=k && i>=j)
            {  
                ans/= nums[j];
                j++; 
            }
           
            res+= i-j+1;
             i++;
        }
            
           
        

        return res;  
    }
};