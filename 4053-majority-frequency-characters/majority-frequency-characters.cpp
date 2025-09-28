class Solution {
public:
    string majorityFrequencyGroup(string s) {
        
        map<char,int>mp;

        map<int,int>mp1;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }

        vector<pair<int,char>>v;

        for(auto it:mp)
        { 

            v.push_back({it.second,it.first});
            
        }

         for(auto it:mp)
        { 

            mp1[it.second]++;
            
        }

         int maxi = 0;

         int c=0;


          for(auto it:mp1)
        { 

            if(it.second>=c)
            {
            
            c = it.second;

            maxi = max(maxi,it.first);

                
            }
            
        }

        cout <<maxi<<endl;

        


        sort(v.begin(),v.end());

        reverse(v.begin(),v.end());

       
        string ans = "";

        


        for(int i=0;i<v.size();i++)
        {
          if(maxi == v[i].first)
          {
            ans+=v[i].second;
          }
         
        }

        return ans;


    }
};