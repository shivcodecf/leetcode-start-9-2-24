class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        vector<int>v1(n),v2(n);

        int maxi=-1;

        for(int i=0;i<n;i++)
        {
          maxi = max(maxi,height[i]);
          v1[i]=(maxi);
        }

        maxi=-1;

          for(int i=n-1;i>=0;i--)
        {
          maxi = max(maxi,height[i]);
          v2[i]=(maxi);
        }

        int ans=0;

        // reverse(v2.begin(),v2.end());

        for(int i=1;i<n-1;i++)
        {
           
        int x = v1[i-1];

        int y = v2[i+1];

        if(x>height[i] && y>height[i])
        {
            int mini = min(x,y);

            int left = mini-height[i];

            ans+=left;
        }

        



        }

        return ans;










































        
    }
};