class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long ans1 = 1LL * need1 * cost1;

        long long ans2 = 1LL * need2 * cost2;

        long long ans3 = 1LL * max(need1,need2) * costBoth;

        long long x=0,y=0,z=0,ans4=LLONG_MAX;

        

        if(need1>need2)
        {
          x = 1LL * need2 * costBoth;
          y = 1LL * (need1-need2)*cost1;
          ans4 = (long long)x+y;

        }
        else if(need2>need1)
        {
             x = 1LL * need1 * costBoth;
             y = 1LL * (need2-need1)*cost2;
             ans4 = (long long)x+y;
        }

        return min({ans1+ans2,ans3,ans4});
        
    }
};