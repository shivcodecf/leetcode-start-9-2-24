#define ll long long

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {

     int n=nums.size(),maxi=-1;

     priority_queue<pair<ll,ll>>q;
     map<ll,ll>mp,mp1;
     vector<ll>ans; 

    //  for(int i=0;i<n;i++)
    //  {
    //     if(mp.find(nums[i])==mp.end())
    //     {
    //         mp[nums[i]]+=freq[i];
    //         maxi=max(maxi,mp[nums[i]]);

    //     }
    //     else {
    //           mp.erase(nums[i]); 
    //           mp[nums[i]]+=freq[i];

    //     }
    //  }

     for(int i=0;i<n;i++)
     {
         
         mp[nums[i]]+=freq[i];
         if(mp[nums[i]]>0)
         {
              q.push({mp[nums[i]],nums[i]});
         }
        

     
       
        
       
       while(q.size() && mp[q.top().second]<q.top().first)
       {
        q.pop();
        q.push({mp[nums[i]],nums[i]});
       }
      
       if(q.size())
       {
        ans.push_back(q.top().first);
       }
       else {
          ans.push_back(0);
       }





     }

     return ans;






















    }
};