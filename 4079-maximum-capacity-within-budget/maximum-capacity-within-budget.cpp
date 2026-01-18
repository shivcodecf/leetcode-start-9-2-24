class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {

     vector<pair<int,int>>v;

     int n = costs.size();

     for(int i=0;i<n;i++)
     {
        v.push_back({costs[i],capacity[i]});
     }

     sort(v.begin(),v.end());

     int ans = 0;

     vector<int>pref(n,0);

     pref[0] = v[0].second;

     for(int i=1;i<n;i++)
     {
       pref[i] = max(pref[i-1],v[i].second);
     }

     for(int i=0;i<n;i++)
     {
        if(v[i].first<budget)
        {  
            int l = 0;
            int h = i-1;

            int sum = v[i].second;

            int sum1 = 0;

            while(l<=h)
            {
                int mid = l+(h-l)/2;

                if(v[mid].first+v[i].first<budget)
                {
                    sum1 = pref[mid];
                    l = mid+1;
                }
                else {
                    h = mid-1;
                }
            }

            ans = max(ans,sum+sum1);
        }
     }

     return ans;

        
    }
};