#define ll long long

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {

     vector<ll>v(n);

     for(ll i=0;i<n;i++)
     {  
        v[i]=1;
     }   

     for(ll i=1;i<=k;i++)
     {   
        ll sum=0;

        for(ll j=0;j<n;j++)
        {
          sum+=v[j];
          sum=sum%1000000007;
          v[j]=sum;
        }

     }

     return v[n-1];

    }
};