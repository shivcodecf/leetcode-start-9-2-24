class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        vector<int>v;
        int ans=0,check=-1;
        
        for(int i=0;i<arr.size();i++)
        { 

          v.push_back(arr[i]);

          if(v.size()==0) continue;

           sort(v.begin(),v.end());

          if(v.size()==1)
          {
            if(v[0]==check+1)
            {
                ans++;
                check=v[0];
                v.clear();
            }
          }

         

          int flag=0;

          if((v[0])!=check+1)
          {
            continue;
          }

          for(int j=1;j<v.size();j++)
          {
             if(v[j]-v[j-1]!=1)
             {
                flag=1;
                break;
             }
          }

          if(flag==0)
          {
             ans++;
             check=v[v.size()-1];
             v.clear();
          }



        }

        return ans;

        
    }
};