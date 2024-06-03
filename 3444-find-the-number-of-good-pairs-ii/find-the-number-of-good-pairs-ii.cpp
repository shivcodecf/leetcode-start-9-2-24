class Solution {
public:
#define ll long long 
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {


        map<ll,ll>mp;

        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]*k]++;
        }


        ll ans=0;

        for(int i=0;i<nums1.size();i++)
        {    

        



            if(nums1[i]%k!=0   )
            {
                continue;
            }

            ll x= sqrt(nums1[i]);

            for(int j=1;j<=x;j++)
            {   




                if(nums1[i]%j!=0 ) continue;

                ll check = (nums1[i]/j);

                ans+=mp[j];

                if(check!=j)
                {
                    ans+=mp[check];
                }









            }



        }

        return ans;

   



    }
};