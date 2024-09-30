#define ll long long

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(),nums.end());

        ll n=nums.size();


        vector<ll>pref(n,0);


        pref[0] = nums[0];


        vector<ll>ans;


        for(ll i=1;i<nums.size();i++)
        { 

           pref[i] = pref[i-1] + nums[i];

        }

        
        for(auto x:queries)
        { 

            ll upper = upper_bound(nums.begin(),nums.end(),x)-nums.begin();

            if(upper<n && upper>0)
            {
                 ll leftSum = x*upper - pref[upper-1];

                 ll y = pref[n-1] - pref[upper-1];

                 ll rightSum = y - (x*(n-1-upper+1));

                 ans.push_back(leftSum + rightSum);
            }

            else {
                 
                 ll total =0;
                 
                if(upper==0)
                {
                    total =  (pref[n-1]) - ((n)*x) ;
                }
                else {
                      total = ((n)*x) - (pref[n-1]);
                }
                

                ans.push_back(total);

            }





        }

        return ans;


    }
};