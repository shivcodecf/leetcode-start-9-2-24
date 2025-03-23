class Solution {
public:
    int beautySum(string s) {
        
         int ans=0;

        for(int i=0;i<s.size();i++)
        {     

            string s1="";

            unordered_map<char,int>mp;

            

            for(int j=i;j<s.size();j++)
            {
              
               mp[s[j]]++; 

              int maxi=INT_MIN,mini=INT_MAX,flag=0;

              if(mp.size()>1)
              {  
                flag=1;
               for(auto it:mp)
               {
                  maxi = max(maxi,it.second);

                  mini = min(mini, it.second);
               }
              }
                
               
              
              
               if(flag)
               ans+=maxi-mini;
          
             
             

            //   cout <<s1<<" "<<maxi-mini<<endl;

            }

        
        }

         return ans;

    }
};