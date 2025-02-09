class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        
        map<int,int>mp;

        int m= elements.size();

        for(int i=m-1;i>=0;i--)
        {
            mp[elements[i]] = i;
        }

        int n = groups.size();

        vector<int>ans;


        for(int i=0;i<n;i++)
        {  
            int mini = INT_MAX;

            for(int j=1;j<=sqrt(groups[i]);j++)
            {
               

                  if(groups[i]%j==0)
                  { 

                    if(mp.find(j)!=mp.end())
                    {
                      mini = min(mp[j],mini);
                    }
                   
                    
                    int x = groups[i]/j;

                    if(mp.find(x)!=mp.end())
                    {
                       mini = min(mp[x],mini);
                    }

                  }
                 
                
            }

            if(mini!=INT_MAX)
            {
                ans.push_back(mini);
            }
            else {
                ans.push_back(-1);
            }

        }

        return ans;

    }
};