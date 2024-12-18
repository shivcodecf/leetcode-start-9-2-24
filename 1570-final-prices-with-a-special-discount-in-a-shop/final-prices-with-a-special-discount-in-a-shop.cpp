class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n=prices.size();

         stack<int>st;
 
         vector<int>ans;

        for(int i=n-1;i>=0;i--)
        { 

           while(!st.empty() && st.top()>prices[i])
           {
            st.pop();
           }

           if(st.size())
           {
            ans.push_back(prices[i]-st.top());
           }
           else {
            ans.push_back(prices[i]);
           }

           st.push(prices[i]);


        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};