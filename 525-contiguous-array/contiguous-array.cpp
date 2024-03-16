class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       
        
        map<int,int>mp{{0,-1}};

        int prefsum=0,ans=0;

        for(int i=0;i<nums.size();i++)
        {
            prefsum+= nums[i]==1 ? 1:-1;

            if(mp.count(prefsum))  ans=max(ans,i-mp[prefsum]);
            else 
            mp[prefsum]=i;
        }

        return ans;
       





       
       

    }
};