class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int n=nums.size();

        vector<int>pref(n),pref1(n);

        pref[0] = nums[0];

        if(n==1)
        {
            if(nums[0]==0)
            {
                return 2;
            }
        }

        for(int i=1;i<n;i++)
        {
           pref[i] = pref[i-1] + nums[i];
        }

        int sum=0;

        for(int i=n-1;i>=0;i--)
        { 
            sum+=nums[i];
            pref1.push_back(sum);
        }

        reverse(pref1.begin(),pref1.end());

        sum=0;

        int ans=0;

        for(int i=0;i<n;i++)
        {   
            if(i>0 && i<n-1)
            { 

              if(nums[i]==0)
            {
                int x = pref[i-1];
                int y = pref1[i+1];

                if(x==y)
                {
                    ans+=2;
                }

                else if(abs(x-y)==1)
                {
                    ans++;
                }
            }

            }

            if(i==0 && nums[i]==0)
            {
                int x = pref1[i+1];

                if(x==1)
                {
                    ans++;
                }
                else if(x==0)
                {
                    ans+=2;
                }
            }

             if(i==n-1 && nums[i]==0)
            {
                int x = pref[i-1];
                if(x==1)
                {
                    ans++;
                }
                else if(x==0)
                {
                    ans+=2;
                }
            }
           
        }

        return ans;











    }
};