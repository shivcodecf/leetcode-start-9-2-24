class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int sum1 = 0 , sum2 = 0;

        for(int i=1;i<=2*n;i++)
        {
            if(i%2)
            {
                sum1+=i;
            }
            else {
                sum2+=i;
            }
        }

        return __gcd(sum1,sum2);
    }
};