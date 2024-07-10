class Solution {
public:
    int minOperations(vector<string>& logs) {

         int ans=0;

       for(int i=0;i<logs.size();i++)
       {  

        int point=0,slash=0;
        for(int j=0;j<logs[i].size();j++)
        {
            if(logs[i][j]=='.')
            {
              point++;
            }
            else if(logs[i][j]=='/')
            {
                slash++;
            }
            
        }

        if(slash==1 && point==2)
        {  
            if(ans>0)
            {
             ans--;
            }
            
        }
        else if(slash==1 && point==0)
        {
            ans++;
        }
       }
       return max(ans,0);

    }
};