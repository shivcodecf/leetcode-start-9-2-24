class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

      vector<pair<string,int>>v;

      int n=words.size();

      map<string,vector<int>>mp;

    

      

      for(int i=0;i<n;i++)
      {   

       

        for(int j=0;j<words[i].size();j++)
        {  

             string s1 ="";

           for(int k=j;k<words[i].size();k++)
           {
                 s1+=words[i][k];

                 mp[s1].push_back(i);
           }
          

        
        }



      }

      vector<string>v1;

    //   for(auto it:mp)
    //   {
        
    //     int x = it.second.size();

    //     map<int,int>mp1;

    //     for(int j=0;j<x;j++)
    //     {
    //         mp1[it.second[j]]++;
    //     }

    //     if(mp1.size()>1)
    //     {
    //         v1.push_back(it.first);
    //     }

        




    //   }

    for(int i=0;i<n;i++)
    { 

        string s2 = words[i];
        int flag=0;

        for(auto it:mp)
        {   
            if(s2 == it.first)
            { 
              
               for(int j=0;j<it.second.size();j++)
            {
                if(i!=it.second[j])
                {
                    flag =1;
                    break;
                }
            }

            }
           
        }

        if(flag)
        {
            v1.push_back(s2);
        }


    }

      return v1;




    }
};