class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        vector<int>mp(k,0);

        

        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            int x = arr[i]%k;

             x = (x+k)%k;

           

           
            mp[x]++;


            

            
        }

        if(mp[0]%2!=0) return false;

        for(int rem = 1;rem<=k/2;rem++)
        {  
              int check = k-rem;
              if(mp[rem]!=mp[check])
              return false;
        }

        return true;




    }
};