class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        

        map<int,int>mp;
        

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }


        int ans = 0;




        for(int i=k;i<=100;i+=k)
        {

            if(mp[i]==0)
            {
                return i;
            }

        }

        return ((100/k)+1)*k;



        
    }
};