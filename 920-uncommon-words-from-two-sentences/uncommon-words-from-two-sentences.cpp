class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

         map<string,int>mp;

         vector<string>v,v1;

         string s3="",s4="";
        
        for(int i=0;i<s1.size();i++)
        {  
            if(s1[i]!= ' ')
            {
              s3+=s1[i];
            }
            else {
                v.push_back(s3);
                s3="";
            }
           
        }

        v.push_back(s3);

         for(int i=0;i<s2.size();i++)
        {  
            if(s2[i]!= ' ')
            {
               s4+=s2[i];
            }
            else {
                   v1.push_back(s4);
                    s4="";
            }
           
        }

         v1.push_back(s4);

        for(int i=0;i<v.size();i++)
        { 
           mp[v[i]]++;
           
        }

         for(int i=0;i<v1.size();i++)
        { 
           mp[v1[i]]++;
           
        }

        for(int i=0;i<v.size();i++)
        {
            cout <<v[i]<<" ";
        }

        //  for(int i=0;i<s2.size();i++)
        // {
        //    if(s1[i]!= ' ')
        //     {
        //        mp[s2[i]]++;
        //     }
        // }

        vector<string>ans;

        for(auto i:mp)
        { 

            if(i.second==1)
            {
                ans.push_back(i.first);
            }

        }



        return ans;


    }
};