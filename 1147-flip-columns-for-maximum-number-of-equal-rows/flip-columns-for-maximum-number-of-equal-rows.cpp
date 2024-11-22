


class Solution {
    
    int solve(int ind,vector<vector<int>>& matrix,string& s)
    {  
         int n=matrix.size(),m=matrix[0].size(),check=0;

         string s1="";

         for(int i=0;i<s.size();i++)
         {
            if(s[i]=='1')
            {
                s1+='0';
            }
            else {
                s1+='1';
            }
         }

      for(int i=0;i<n;i++)
      { 

        if(i==ind)
        {
            continue;
        }

        int flag=0,flag1=0;

        for(int j=0;j<m;j++)
        {
             if(matrix[i][j]==s[j]-'0')
             {
                continue;
             }
             else {
                flag=1;
                break;
             }
        }

        for(int j=0;j<m;j++)
        {
             if(matrix[i][j]==s1[j]-'0')
             {
                continue;
             }
             else {
                flag1=1;
                break;
             }
        }

        if(flag==0 || flag1==0 )
        {
            check++;
        }


      }

      return check;


    }

public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
     
     int n=matrix.size(),m=matrix[0].size();

      map<int,int>mp;

     for(int i=0;i<n;i++)
     {   

         string s1 ="";

        for(int j=0;j<m;j++)
        {
         s1+=matrix[i][j]+'0';
        }

         int res=0;

          res = solve(i,matrix,s1);
        
          mp[i]+=res+1;
       

        
     }

     int ans1=0;

     for(int i=0;i<n;i++)
     {  
        int flag=0;
        for(int j=0;j<m-1;j++)
        {
            if(matrix[i][j]==matrix[i][j+1])
            {
              continue;
            }
            else {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
         ans1++;
        }
     }

     int ans=0;

     for(auto it:mp)
     {
        ans = max(ans,it.second);
     }

     return max(ans,ans1);

     

    }
};