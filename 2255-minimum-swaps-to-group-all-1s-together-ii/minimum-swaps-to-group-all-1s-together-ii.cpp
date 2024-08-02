class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        vector<int>v,v1;
        int sum=0,one=0;
        for(int i=0;i<nums.size();i++)
        {
            v1.push_back(nums[i]);
        }

        for(int i=0;i<nums.size();i++)
        {
            v1.push_back(nums[i]);
        }

        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==1)
            {
                sum+=v1[i];
                one++;
            }

            v.push_back(sum);
        }

        one = one/2;

        int i=0,j=0;
        int ans=INT_MAX,c=0,on=0,zero=0;

        for(int i=one-1;i<v.size();i++)
        {
             c++;
             if(c==1)
             {
                zero = one - v[i];
                ans=min(ans,zero);

             }
             else {
                 on = v[i] - v[j];
                 zero = one - on;
                ans=min(ans,zero);
                j++;
             }

        }

        if(ans==INT_MAX) return 0;

        return ans;



        
    }
};