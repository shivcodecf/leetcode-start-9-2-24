class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        
        map<string,vector<int>>mp;

        int n=responses.size(),m=responses[0].size();


        for(int i=0;i<n;i++)
        {   
            int m = responses[i].size();

            map<string,int>mp1;
            for(int j=0;j<m;j++)
            {  
                if(mp1.find(responses[i][j])==mp1.end())
                {
                   mp[responses[i][j]].push_back(i);
                   mp1[responses[i][j]]++;
                }
                
            }
        }

        string res = "";

        int f = 1;

        vector<string>v1;

        for(auto it:mp)
        {
            if(it.second.size()>f)
            {
                f = it.second.size();
                res = it.first;

            }

            if(it.second.size()==1)
            {
                v1.push_back(it.first);
            }
          
        }

        sort(v1.begin(),v1.end());

        if(f==1)
        {
            return v1[0];
        }


        




        return res;



    }
};