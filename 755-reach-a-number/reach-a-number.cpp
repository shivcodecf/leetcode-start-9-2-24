class Solution {
public:
    int reachNumber(int target) {
        // Convert target to a positive value since the problem is symmetric
        target = abs(target);
        
        long long sum = 0;
        int steps = 0;
        
        // Keep incrementing steps until the sum is greater than or equal to the target
        // and the difference between sum and target is even.
        while (sum < target || (sum - target) % 2 != 0) {

            steps++;
            
            sum += steps;


        }
        
        return steps;
    }
};
