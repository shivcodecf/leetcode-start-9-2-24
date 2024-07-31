class Solution {
public: 

   bool solve(int i,int j,int p1,int p2,bool flag,vector<int>&nums){
        if(i>j){
            return p1>=p2;
        }
        bool pf = false, ps = false;
        if(flag){
            pf =  solve(i+1,j,p1+nums[i],p2,!flag,nums) || solve(i,j-1,p1+nums[j],p2,!flag,nums);
        }else{
            ps =  solve(i+1,j,p1,p2+nums[i],!flag,nums) && solve(i,j-1,p1,p2+nums[j],!flag,nums);
        }

        return pf || ps;
    }

    bool predictTheWinner(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int p1=0,p2=0;
        bool flag=true;
        return solve(i,j,p1,p2,flag,nums); 
    }
};