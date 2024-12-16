class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        auto com = [](const pair<int,int>&a ,const pair<int,int>& b)
        {
            if(a.first==b.first)
            {
                return a.second < b.second;
            }

            return a.first < b.first;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        while(!pq.empty())
        { 

          auto it = pq.top();

          pq.pop();

          int x = it.first;

          int y = it.second;

          pq.push({x*multiplier,y});

          k--;

          if(k==0)
          {
            break;
          }




        }

        

         vector<pair<int,int>>v1;

        while(!pq.empty())
        {  
            auto it = pq.top();
            pq.pop();
            v1.push_back({it.second,it.first});

        }

        sort(v1.begin(),v1.end());

        vector<int>ans;

       

        for(int i=0;i<v1.size();i++)
        {
            ans.push_back(v1[i].second);
        }

        return ans;




    }
};