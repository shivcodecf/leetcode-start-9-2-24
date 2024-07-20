#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int n=rowSum.size(),m=colSum.size();
    
        
        vector<vector<int>>v(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(j==m-1)
                {
                   v[i][j] = rowSum[i];
                }
                else{
                    v[i][j] = 0;
                }
               
            }
        }





        vector<int>check;

   



        for(int i=0;i<m;i++)
        {      
            

            int reSum = colSum[i], reSum1 = colSum[i];

            int curSum=0;

            if(i==m-1)
            {
                continue;
            }


            for(int j=0;j<n;j++)
            {    

                // if(i == m-1)
                // {
                //     v[j][i] = 
                // }

                  int start = 0;
                  

                 if(reSum>0)
                 { 

                    if(v[j][m-1]==reSum)
                    {
                         v[j][i] = v[j][m-1];

                        

                         curSum+= v[j][m-1];

                          start = v[j][m-1];

                         reSum-=v[j][m-1];


                        

                          v[j][m-1] -= start;

                    }
                    else if(v[j][m-1]>reSum)
                    {
                      v[j][i] = reSum;

                      curSum+=reSum;

                       start = reSum;

                       reSum = 0;

                      
                        v[j][m-1] -= start;

                    }
                    else if(reSum>v[j][m-1])
                    { 

                        v[j][i] = v[j][m-1];

                        curSum+=v[j][m-1];

                        start = v[j][m-1];

                        reSum-=v[j][m-1];

                        

                        v[j][m-1] -= start;

                    }



                 }

                //  int check =  v[j][m-1] - start;

                //  v[j][m-1] = v[j][m-1] - check;




                 


            }









        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                cout <<v[i][j]<<" ";
               
            }
            cout <<endl;
        }







        return v;



    

    }
};