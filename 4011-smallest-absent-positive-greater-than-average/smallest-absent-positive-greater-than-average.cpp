class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        
        int sum =0;

        map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mp[nums[i]]++;
        }

        int n = nums.size();

        int avg = sum/n;

        sort(nums.begin(),nums.end());

        for(int i=1;i<=100;i++)
        {
            if(mp.find(i)==mp.end() && i>avg)
            {
                return i;
            }
        }

        return 101;

        



       

    }
};