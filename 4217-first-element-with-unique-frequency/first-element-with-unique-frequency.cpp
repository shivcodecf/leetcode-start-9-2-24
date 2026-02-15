class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        map<int,int>mp,mp1,mp2,mp3;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            mp3[nums[i]] = i;
            
        }

        for( auto it:mp)
        {
          mp1[it.second]++;
          mp2[it.second] = it.first;
        }

        vector<int>ans;

        

        for(auto it:mp1)
        {
            if(it.second == 1)
            {
                ans.push_back(mp2[it.first]);
            }
        }

        if(ans.size() ==0)
        {
            return -1;
        }

        int mini = INT_MAX;

        int sol = 0;


        for(int i=0;i<ans.size();i++){

            if(mp3[ans[i]]<mini)
            {
              sol = ans[i];
              mini = min(mini,mp3[ans[i]]);

            }
        }

        return sol;


        
    }
};