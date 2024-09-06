
#define ll long long
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
           

        auto custom = [](const pair<ll,ll>& a, const pair<ll,ll>& b)
        { 

            double x = static_cast<double>(a.second) / static_cast<double>(a.first);



             double y = static_cast<double>(b.second) / static_cast<double>(b.first);


             return x>y;

        };


           int n=damage.size();
     
          vector<pair<ll,ll>>v;

          for(int i=0;i<n;i++)
          {  


            ll x =  (health[i]/power);

            if(health[i]%power)
            {
                x++;
            }


           

             v.push_back({x,damage[i]});

          }

           sort(v.begin(),v.end(),custom);

          

           ll total = accumulate(damage.begin(),damage.end(),0);
           ll ans=0;


           for(int i=0;i<v.size();i++)
           {  

               ll x= total * v[i].first;
               ans+= x;

               total = total - v[i].second;






              

           } 

           return ans;

    }
};