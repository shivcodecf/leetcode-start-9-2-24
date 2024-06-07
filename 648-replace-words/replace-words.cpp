#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        
        int n=dictionary.size(),m=sentence.size();

        map<string,string>mp;

        vector<pair<int,string>>v;

        for(int i=0;i<n;i++)
        {
            v.push_back({dictionary.size(),dictionary[i]});
        }

        vector<string>words;
        string insert="";

        for(int i=0;i<m;i++)
        {    
            if(sentence[i]==' ')
            {
                words.push_back(insert);
                insert="";
            }
            else {
               insert+=sentence[i];
            }
        }

        words.push_back(insert);


         sort(v.begin(),v.end());
         reverse(v.begin(),v.end());


        for(int i=0;i<n;i++)
        {
            int x=v[i].second.size();

            int len=0;

            for(int j=0;j<words.size();j++)
            { 

                string s1=words[j].substr(0,x);

                if(s1==v[i].second)
                {
                    mp[words[j]] = v[i].second; 
                }
               

            }


        }

        string ans="";
        

        for(int i=0;i<words.size();i++)
        {    

            
           if(i!=words.size()-1)
           {   
            if(mp.find(words[i])==mp.end())
            {
                ans+=words[i];
                ans+=" ";
                continue;
            }
              ans+=mp[words[i]];
              ans+=" ";
           }
           else { 
            if(mp.find(words[i])==mp.end())
            {
                ans+=words[i];
                 continue;
            }

                ans+=mp[words[i]];
           }

          

        }

        

       

        return ans;






    }
};