class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {


        
        map<int,vector<int>>mp;
        map<int,int>mp1;
        for(int i=0;i<trust.size();i++)
        {
        
         mp[trust[i][0]].push_back(trust[i][1]);

        } 

           if(n==1)
           {
               return 1;
           }

         for(auto i:mp)
         {
             for(int j=0;j<i.second.size();j++)
             {
                 mp1[i.second[j]]++;
             }
         }

         int ans=-1;
         int check=mp.size();

         for(auto i:mp1)
         {
             if(i.second==check)
             {
                 ans=i.first;
             }
         }
         if(mp.size()==(n-1))
         return ans;
         return -1;


        







     
        


       
        


        

       


    }
};