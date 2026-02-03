class Solution {
   
   int solve(vector<int>& nums , int mid)
   {    

     
      int temp = 0;

      for(int i=0;i<nums.size();i++)
      {
       temp+=nums[i]/mid + (nums[i]%mid == 0 ? 0 :1);
      }

      return temp;

      


   }


public:
    int minimumK(vector<int>& nums) {

        int n = nums.size();
        
        long long low = 1, high = *max_element(nums.begin(),nums.end())+n;

        long long ans = INT_MAX;

        while(low<=high)
        {
            long long mid = low+(high-low)/2;

            long long check = INT_MAX;
             
           
            check = solve(nums,mid);

            if(check<=mid*mid)
            {

                ans = min(ans,mid);

                cout <<check<<""<<mid<<endl;;

                high = mid-1;

            }
            else {
                 
                 low = mid+1;
            }
           
        }

        return ans;

        // 3 + (7-3)/2 

        // 3+2 = 5

        // temp = 1+2+1 = 4

        // 4<=25

        // high = 4;

        // low = 3

        // 3+(4-3)/2 = 3

        // 

    }
};