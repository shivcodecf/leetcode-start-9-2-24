class Solution {
public: 

bool solve(int num1,int num2)
{     
      vector<pair<int,int>>v1;

    while(num1>0 || num2>0)
    { 
          int x = num1%10;
          int y= num2%10;

          

           if(num1!=0) num1 = num1/10;
           if(num2!=0) num2 = num2/10;

           if(x!=y)
           {
            v1.push_back({x,y});
           }


    }

    if(v1.size()==1) return false;
     if(v1.size()==0) return true;

    

    if(v1.size()>2 ) return false;

    if(v1[0].first==v1[1].second && v1[0].second==v1[1].first) return true;

    return false;








   

    
}

    int countPairs(vector<int>& nums) {
        
       int n=nums.size(),ans=0;

       for(int i=0;i<n-1;i++)
       {
        for(int j=i+1;j<n;j++)
        {
           if(solve(nums[i],nums[j]))
           {
            ans++;
           }
        }
       }

       return ans;


    }




       
};
