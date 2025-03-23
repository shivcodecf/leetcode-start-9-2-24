class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {

        int check = maxWeight/w;

        return min(n*n,check);

    }
};