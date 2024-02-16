class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
      int n=nums.size();

      map<int,int>mp,mp1;
      for(int i=0;i<n;i++)
      {
          mp[nums[i]]++;
      }
      vector<pair<int,int>>v;

      for(auto i:mp)
      {
        v.push_back({i.second,i.first});
      }

      sort(v.begin(),v.end());
      int sum=0,ans=v.size();

      for(int i=0;i<v.size();i++)
      {
        if(v[i].first<=k )
        {  
            k-=v[i].first;
            v[i].first=0;
            ans--;
         
           
        }
        
        else if(v[i].first>k )
        {   
            
             
             break;
            
           
        }
       
      }
      
      
      return ans;




    }
};