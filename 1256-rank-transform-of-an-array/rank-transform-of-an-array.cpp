class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       
    
       vector<pair<int,int>>ans;

       for(int i=0;i<arr.size();i++)
       { 

        ans.push_back({arr[i],i});

       }

          sort(ans.begin(),ans.end());

        



       map<int,int>mp,mp1;

       int cnt = 1;

       for(int i=0;i<arr.size();i++)
       { 

        if(mp1.find(ans[i].first)!=mp1.end())
        {
            mp[ans[i].first] = cnt-1;
        }
        else {
            mp[ans[i].first] = cnt;
            cnt++;
        }
       
        mp1[ans[i].first]++;

       }
       

       vector<int>res;
    

       for(int i=0;i<arr.size();i++)
       {
         res.push_back(mp[arr[i]]);
       }

       return res;

       


    }
};