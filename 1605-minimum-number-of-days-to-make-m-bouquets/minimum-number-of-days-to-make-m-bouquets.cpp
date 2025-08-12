class Solution {

       bool check(vector<int>& bloomDay,int target,int k,int m)
       { 

          int n = bloomDay.size();

          map<int,int>mp;

          int check = 0,sum=0;

          // [1,10,3,10,2]

          for(int i=0;i<n;i++)
          { 

             if(bloomDay[i]<=target)
             {
                check++;
             }
             else{
                check=0;
             }

             if(check==k)
             {
                sum++;
                check=0;
             }

             if(sum == m)
             {
                return true;
             }

          }

          return false;


       }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         
         int n = bloomDay.size();


         int high = *max_element(bloomDay.begin(),bloomDay.end());

         

         int low = *min_element(bloomDay.begin(),bloomDay.end());


         cout <<high <<" "<<low<<endl;

         int ans = INT_MAX;


         while(low<=high)
         {  

            int mid = low+(high-low)/2;

            if(check(bloomDay,mid,k,m))
            {
                high = mid-1;
                ans = min(ans,mid);
            }
            else {
                low = mid+1;
            }


         }

         if(ans == INT_MAX)
         {
            return -1;
         }

         return ans;


    }
};