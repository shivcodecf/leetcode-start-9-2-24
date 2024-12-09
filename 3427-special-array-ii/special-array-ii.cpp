class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();

        vector<int>pref(n,0);

        pref[0] = 0;

        for(int i=1;i<n;i++)
        {
           if(nums[i-1]%2!=nums[i]%2)
           {
            pref[i] = pref[i-1]+1;
           }
           else {
            pref[i] = 0;
           }
        }

        int m=queries.size();

        vector<bool>v1;

        for(int i=0;i<m;i++)
        {
            int x = queries[i][0];

            int y = queries[i][1];

            if(pref[y]-pref[x]==y-x)
            {
             v1.push_back(true);
            }
            else {
                v1.push_back(false);
            }


        }

        return v1;








    }
};