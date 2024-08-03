
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    auto customComparator = [] (const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b)
    {
        if(a.second.first == b.second.first)
        {
            return a.first < b.first;
        }

        return a.second.second < b.second.second;
    };

       vector<pair<int,pair<int,int>>>v;

       int n= intervals.size();

       for(int i=0;i<n;i++)
       {  

        int x = abs(intervals[i][1] - intervals[i][0]);

        v.push_back({x,{intervals[i][0],intervals[i][1]}});


       }

        sort(v.begin(),v.end(),customComparator);

        int check = v[0].second.first;
        int check1 = v[0].second.second;
        int ans=1;  

        for(int i=0;i<n;i++)
       {  

          cout <<v[i].second.first<<" "<<v[i].second.second<<endl;

       }

       for(int i=1;i<v.size();i++)
       {
          int y = v[i].second.first;

          if(y>=check1)
          {
            check1 = v[i].second.second;
            ans++;
          }

       }

       return n-ans;



    }
};