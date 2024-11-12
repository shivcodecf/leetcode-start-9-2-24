class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {



        auto comparator = [](const pair<int,int>& a,pair<int,int>& b)
        {
            if(a.first==b.first)
            {
                return a.second < b.second;
            }
            return a.first < b.first;
        };
        
     vector<pair<int,int>>v;

     for(int i=0;i<items.size();i++)
     {  
        v.push_back({items[i][0],items[i][1]});
     }

     sort(v.begin(),v.end(),comparator);

     vector<pair<int,pair<int,int>>>v1;

     int maxi = -1;

     for(int i=0;i<items.size();i++)
     {    
         maxi = max(maxi,v[i].second);
        v1.push_back({v[i].first,{v[i].second,maxi}});
     }




     

     int n=v.size();

     vector<int>ans;

     for(int i=0;i<queries.size();i++)
     {
        int s = 0;
        int e = n-1;

        int value = queries[i],an=INT_MIN;

        while(s<=e)
        {
            int mid = s+(e-s)/2;

            if(v1[mid].first<=value)
            {   
                an = max(an,v1[mid].second.second);
                s = mid+1;
            }
            else {
              e = mid-1;
            }

            
        }
         
         if(an!=INT_MIN)
        ans.push_back(an);
        else {
            ans.push_back(0);
        }


     }

     return ans;





    }
};