class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        

        auto customComparator = [](const pair<int,int>& a,const pair<int,int>& b)
      { 

        if(a.first==b.first)
        {
         return a.second>b.second;
        }

        return a.first<b.first;

      };


      map<int,int>mp;

      for(int i=0;i<nums.size();i++)
      {
        mp[nums[i]]++;
      }  

      vector<pair<int,int>>v;

      for(auto i:mp)
      {
        v.push_back({i.second,i.first});
      }

      

      sort(v.begin(),v.end(),customComparator);


      vector<int>ans;

      for(int i=0;i<v.size();i++)
      {
        while(v[i].first--)
        {
            ans.push_back(v[i].second);
        }

      }
      return ans;




    }
};