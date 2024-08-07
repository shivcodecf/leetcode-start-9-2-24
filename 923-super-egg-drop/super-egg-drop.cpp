class Solution {  

     int t[101][10001];
  
  int binarySearch(int e, int f) {
        if(e == 1 || f == 0 || f == 1)
            return f;
        
        if(t[e][f] != -1)
            return t[e][f];
        
        int l = 0, h = f;

        int minAttempts = INT_MAX;

        while(l <= h) {
            int mid = l + (h-l)/2;
            
            int breaks   = binarySearch(e-1, mid-1);
            int no_break = binarySearch(e, f-mid);
            int temp     = 1 + max(breaks, no_break);
            minAttempts  = min(minAttempts, temp);
            
            if(l == h)
                break;
            
            if(breaks < no_break)
                l = mid+1;
            else
                h = mid-1;
        }
        
        return t[e][f] = minAttempts;
    }

public:
    int superEggDrop(int e, int f) {
     
        memset(t, -1, sizeof(t));
        //return solve(e, f); //Recursoin + Memoization (TLE)
        
        //return solve_iter(e, f); //DP (TLE)
        
        //return binarySearch(e, f); //Binary Search + Memoized (Accepted)
        
        return binarySearch(e, f); //Iterative Binary Search (Accepted)

    }
};