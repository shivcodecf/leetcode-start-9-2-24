class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
          
          vector<int>v;
          int n=nums.size();

    //   for(int i=0;i<nums.size();i++)
    //   {
    //     v.push_back(nums[i]);
    //   } 

        stack<int>st;

    //    for(int i=0;i<nums.size();i++)
    //   {  
        
    //     v.push_back(nums[i]);
    //   }
      
       for(int i=n-1;i>=0;i--)
      {  
        st.push(nums[i]);
        
      }
      
     
       vector<int>ans;

      for(int i=n-1;i>=0;i--)
      {
         
         while(st.size() && st.top()<=nums[i])
         {
            st.pop();
         }
         if(st.empty())
         {
            ans.push_back(-1);
         }
         else {
            ans.push_back(st.top());
         }
         st.push(nums[i]);

      }
      reverse(ans.begin(),ans.end());
      return ans;
      

    }
};