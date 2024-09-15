class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int>st;

        for(int i=nums.size()-1;i>=0;i--)
        {
            st.push(nums[i]);
        }

        vector<int>ans;

        for(int i=nums.size()-1;i>=0;i--)
        {     
              int flag=0;
              if(st.empty())
              {
                ans.push_back(-1);
                continue;
              }

              while(!st.empty())
              {
                int x=st.top();
                if(nums[i]<x)
                {    
                    flag=1;
                    ans.push_back(x);
                    break;
                }
                st.pop();
                
              }

              st.push(nums[i]);

              if(!flag)
              {
                ans.push_back(-1);
              }
        }

        reverse(ans.begin(),ans.end());

        return ans;









    }
};