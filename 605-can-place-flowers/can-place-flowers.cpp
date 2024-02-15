class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int ans=0,m=flowerbed.size();
       if(m==1)
       {
           if(flowerbed[0]==0 )
           {
               if(n<=1)
               return true;
           }
           if(flowerbed[0]==1 && n==0)
           {
               return true;
           }
          

           else 
           return false;

       }
       if(flowerbed[0]==0 && flowerbed[1]==0)
       {    
           flowerbed[0]=1;
           ans++;
       }
       for(int i=1;i<m-1;i++)
       {
           if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0)
           {  
               flowerbed[i]=1;
               ans++;
           }

       }
       if(flowerbed[m-1]==0 && flowerbed[m-2]==0)
       {
           ans++;
       }
       if(ans>=n)
       {
           return true;
       }
       return false;
       

        
    }
};