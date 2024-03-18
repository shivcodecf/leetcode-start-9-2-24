class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

      vector<pair<int,int>>v;
      int n=intervals.size();

      for(int i=0;i<n;i++)
      {
        v.push_back({intervals[i][0],intervals[i][1]});
      } 
   

      v.push_back({newInterval[0],newInterval[1]});


      sort(v.begin(),v.end());
       int mini=v[0].first;
    int maxi=v[0].second;

    int prev=v[0].second;
     n=v.size();
    vector<vector<int>>v1;
     vector<int>temp;  

     if(n==1)
     {
        temp.push_back(mini);
        temp.push_back(maxi);
        v1.push_back(temp);
        return v1;
     }
   

    for(int i=1;i<n;i++)
    {    
       
        
        if(prev>=v[i].first)
        {
         maxi=max(maxi,v[i].second);
         mini=min(mini,v[i].first);
         prev=max(prev,v[i].second);

        }
        else{
            temp.push_back(mini);
            temp.push_back(maxi);
            v1.push_back(temp);
               maxi=v[i].second;
               mini=v[i].first;
               prev=v[i].second;
               temp.clear();
        } 
        
        if(i==n-1 )
        {     
           
            temp.push_back(mini);
            temp.push_back(maxi);
            v1.push_back(temp);
        }
         

    }
   
    return v1;







        
    }
};