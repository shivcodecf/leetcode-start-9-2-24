class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        int n = nums.size();

        map<int,vector<int>>mp;

        int maxi = INT_MIN;

        for(int i=0;i<n;i++){

            string s = to_string(nums[i]);

             sort(s.begin(),s.end());

             int diff = (s[s.size()-1]-'0')-(s[0]-'0');

             maxi = max(maxi,diff);

             mp[diff].push_back(nums[i]);

            }
        

        int ans = 0;

        for(auto it : mp[maxi]){
            ans+=it;
        }
        
        return ans;
    }
};