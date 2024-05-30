class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int xr=0,ans=0;

       for(int i=0;i<arr.size()-1;i++)
       { 
           xr=0;
         for(int j=i;j<arr.size()-1;j++)
         {
           xr=xr^arr[j];
           int xr1=0;

           for(int k=j+1;k<arr.size();k++)
           {
              xr1=xr1^arr[k];
              if(xr==xr1)
              {
                ans++;
              }
           }

         }

       }
       return ans;

    }
};