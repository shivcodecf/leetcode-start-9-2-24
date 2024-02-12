class Solution {
public:
    int maxArea(vector<int>& height) {
        long long i=0, j=height.size()-1;
        long long ans=0;
        while(i<j)
        {
            if(height[i]>height[j])
            {
                
                ans=max(ans,min(height[i],height[j])*(j-i));
                j--;
            }
             else  if(height[i]<height[j])
            {
                 ans=max(ans,(j-i)*min(height[i], height[j]) );
                i++;
            }
            else 
            {
                 ans=max(ans,(j-i)*min(height[i], height[j]) );
                 i++;
            }



        }


      return ans;
    }
};