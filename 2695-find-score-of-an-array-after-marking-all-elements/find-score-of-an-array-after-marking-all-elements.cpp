class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        auto comparator = [](const pair<int,int>& a, const pair<int,int>& b)
        {
            if(a.first==b.first)
            {
                return a.second<b.second;
            }

            return a.first<b.first;

        };

        vector<pair<int,int>>v;

        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end(),comparator);

        long long ans=0;

        map<int,int>mp;

        for(int i=0;i<v.size();i++)
        {
            cout <<v[i].first <<" ";
        }

        for(int i=0;i<v.size();i++)
        {
          int x = v[i].first;

          int y= v[i].second;

          if(mp.find(y)==mp.end())
          {
            ans+=x;
            mp[y+1]++;
            mp[y-1]++;
          }


        }

        return ans;


    
    }
};