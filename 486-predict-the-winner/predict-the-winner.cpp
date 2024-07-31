class Solution {
public:
    bool fun(vector<int>& nums,int turn,int i,int j,int player1,int player2){
        if(i>j){
            if(player1>=player2) return true;
            else return false;
        } 
        else
        {
            if(turn%2==0 ){
                 if(fun(nums,turn+1,i+1,j,player1+nums[i],player2) || fun(nums,turn+1,i,j-1,player1+nums[j],player2)  ){
                    return true;
                 }
                 else return false;
            }
            else
            {
                    if(fun(nums,turn+1,i+1,j,player1,player2+nums[i])==false || fun(nums,turn+1,i,j-1,player1,player2+nums[j]) ==false ){
                    return false;
                 }
                 else return true;
            }
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int l=nums.size();
        int dp[l+1][l+1];
        memset(dp, -1, sizeof(dp));
        return  fun(nums,0,0,l-1,0,0);

    }
};