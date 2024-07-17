class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n= mat.size(),m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {     
            int flg=0,flag1=0;

            for(int j=0;j<m;j++)
            {   
                flag1=0;
                if(i-1>=0)
                {
                    if(mat[i][j]>mat[i-1][j])
                    {
                      flg++;
                    }
                    else {
                        flag1=1;
                    }

                }
                    if(i+1<n)
                    {  

                        if(mat[i][j]>mat[i+1][j])
                    {
                      flg++;
                    }
                    else {
                        flag1=1;
                    }


                    }

                     if(j-1>=0)
                    {
                        if(mat[i][j]>mat[i][j-1])
                    {
                      flg++;
                    }
                    else {
                        flag1=1;
                    }
                    }

                      if(j+1<m)
                    {
                        if(mat[i][j]>mat[i][j+1])
                    {
                      flg++;
                    }
                    else {
                        flag1=1;
                    }
                    }



                     if(flag1==0)
                {
                return {i,j};
                }


                
            }
           
        }

        return {-1,-1};


    }
};