class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int size = ranges.size();
        
        int maxi = 0;
        for(int i=0;i<n;i++)    maxi = max(maxi,ranges[i]);

        vector<long> next(size+maxi+1,0),curr(size+maxi+1,0);
        for(int j=0;j<=(size-2);j++)   next[j] = 1e8;

        for(int i=size-1;i>=0;i--){
            for(int prev=size-2;prev>=0;prev--){
                int notPic = 0 + next[prev];
                int Pic = 1e8;
                if( (i - ranges[i] <= prev) ){
                    Pic = 1 + next[i+ranges[i]];
                }
                curr[prev] = min(Pic,notPic);
            }
            next = curr;
        }
        if(next[0] == 1e8){
            return -1;
        }
        return next[0];
    }
};