class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(),happiness.end());
        reverse(happiness.begin(),happiness.end());
        long long n=happiness.size(),sum=0;
        long long x=0,ans=0,c=0;

        for(int i=0;i<n;i++)
        { 
            c++;
           sum = happiness[i]-x;
           if(sum>0)
           {
            ans+=sum;
           }
           x++;
           if(c==k)
           {
            break;
           }
        }

        return ans;
        
        
        
    }
};