
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (right>left) {
           right=right & right-1;
        }
        return right;
    }
};
