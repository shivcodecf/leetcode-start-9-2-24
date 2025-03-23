class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int>v;

        stack<int>st;

        // for(int i=0;i<nums.size();i++)
        // {
        //     v.push_back(nums[i]);
        // }

        for(int i=nums.size()-1;i>=0;i--)
        {
            

            st.push(nums[i]);


        }

        vector<int>ans;

        for(int i=nums.size()-1;i>=0;i--)
        {
           

            while(!st.empty() && nums[i]>=st.top())
            {
                st.pop();
            }

            if(st.size())
            {
                ans.push_back(st.top());
            }
            else {
                ans.push_back(-1);
            }

            st.push(nums[i]);

        }

        reverse(ans.begin(),ans.end());

       

        return ans;





    }
};