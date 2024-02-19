class Solution {
public: 

    bool solve(int n) {   
        if (n == 1) {
            return true;
        }

        if (n % 2 != 0) {
            return false;
        }

        // Return the result of the recursive call
        return solve(n / 2);
    }

    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        }
        if(n==0)
        {
            return false;
        }
        return solve(n);
    }
};
