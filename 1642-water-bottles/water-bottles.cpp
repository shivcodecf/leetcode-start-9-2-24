class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
      int check = numBottles/numExchange;
      int rem = numBottles%numExchange;
      int ans = check+numBottles;
      int total = rem+check;

      while(check>0)
      { 
        

        check  = (total) / numExchange;
        rem  = (total) % numExchange;

        total= check+rem;

        ans+=check;



      }

      return ans;




    }
};