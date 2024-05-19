
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {


     int n=nums.size();
     int m=queries.size();
     vector<bool>ans;

     if(n==1)
     {   

        while(m--)
        {
           ans.push_back(true);
        }
       

        return ans;
     }

     vector<int>v;
     int c=0;
       v.push_back(0);
     for(int i = 0;i<n-1;i++)
     { 
       
      if(nums[i]%2==nums[i+1]%2)
      {
        c++;
        v.push_back(c);
        
      }
      else {
        v.push_back(c);
      }

     }
   
     

       
     

     for(int i=0;i<m;i++)
     {

        int x= queries[i][0];
        int y=queries[i][1];
        
        
       
        

        int diff=v[y]-v[x];

        if(diff<=0)
        {
         ans.push_back(true);
        }
        else {
            ans.push_back(false);
        }


     }

     return ans;






    }
};