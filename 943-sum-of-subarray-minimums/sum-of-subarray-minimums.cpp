const int mod = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long n=arr.size(),ans=0;

      stack<pair<int,int>>stleft,stright;

      vector<int>left(n),right(n);

      for(int i=0;i<n;i++)
      {
        int cnt=1;
        while(stleft.size() && stleft.top().first>arr[i])
        {
            cnt+=stleft.top().second;
            stleft.pop();
        }
        stleft.push({arr[i],cnt});

        left[i]=cnt;




      } 
     

      
       for(int i=n-1;i>=0;i--)
      {
        int cnt=1;
        while(stright.size() && stright.top().first>=arr[i])
        {
            cnt+=stright.top().second;
            stright.pop();
        }
        stright.push({arr[i],cnt});

        right[i]=cnt;




      }
      for(int i=0;i<n;i++)
      {  
        
        long long curr = 
                (1ll * left[i] * right[i] * arr[i]) % mod;
            ans = (ans + curr) % mod;
      }
      return ans;


     


    }
};