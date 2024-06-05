class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        

        map<char,vector<int>>mp;
        int n=words.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                mp[words[i][j]].push_back(i);
            }
        }

       
        map<char,int>mp2;
        for(auto i:mp)
        {     
            map<int,int>mp1;

            for(int j=0;j<i.second.size();j++)
            {
                mp1[i.second[j]]++;
            }
            int mini=INT_MAX;

            if(mp1.size()==n)
            {  
                for(auto it:mp1)
                {
                     mini=min(mini,it.second); 
                }

                while(mini--)
            {
                mp2[i.first]++;
            }
                
            }

            

        }
        vector<string>v;
        

        for(auto i:mp2)
        {    
           string str(1,i.first);
            while(i.second--)
            {
              v.push_back(str);
            }
           
        }

        return v;


    }
};