class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {

        map<int,int>mp;

        int n = bulbs.size();

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            mp[bulbs[i]]++;
        }

        for(auto it:mp)
        {
            if(it.second % 2)
            {
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
        
    }
};