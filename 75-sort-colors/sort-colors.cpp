class Solution {
public:
    void sortColors(vector<int>& nums) {

       map<int,int>mp;
       set<int>st;

       for(int i=0;i<nums.size();i++)
       {
        st.insert(nums[i]);
        mp[nums[i]]++;
       } 

       vector<int>v;

       for( auto i:st)
       {
        int x= i;
        int y= mp[i];
        while(y--)
        {
            v.push_back(x);
        }
       }

       for(int i=0;i<nums.size();i++)
       {
        nums[i]=v[i];
       }
       
       
    }
};