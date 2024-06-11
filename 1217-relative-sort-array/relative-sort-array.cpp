class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    
       int n=arr1.size(),m=arr2.size();
       map<int,int>mp;
       vector<int>ans;

       for(int i=0;i<n;i++)
       {
        mp[arr1[i]]++;
       }

     

       for(int i=0;i<m;i++)
       { 

          int x=mp[arr2[i]];
        

          while(x--)
          {
            ans.push_back(arr2[i]);
            mp[arr2[i]]--;
          }

          
       }

       vector<int>v;

       for(int i=0;i<n;i++)
       {
            if(mp[arr1[i]]>0)
            {
               v.push_back(arr1[i]);
            }
       }

       sort(v.begin(),v.end());

       for(int i=0;i<v.size();i++)
       {
        ans.push_back(v[i]);
       }

       return ans;

    }
};