class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        int cnt=0;

        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {  

           int x = nums[i]+k;

           int y = max(nums[i]-k,0);

           mp[y]++;

           mp[x+1]--;

        }

        int n=nums.size();

        sort(nums.begin(),nums.end());

        int ans=INT_MIN;

        int l = nums[n-1]+k;

        for(int i=0;i<=l;i++)
        {
            cnt+=mp[i];

            ans = max(ans,cnt);


        }

        return ans;

    }
};