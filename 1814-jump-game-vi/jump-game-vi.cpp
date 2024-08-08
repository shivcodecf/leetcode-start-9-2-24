class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        deque<int>dq{0};

        

        int n=nums.size();

        for(int i=1;i<n;i++)
        { 

           nums[i] = nums[i] + nums[dq.front()];

           while(dq.size() && nums[dq.back()]<=nums[i])
           {
            dq.pop_back();
           }

           dq.push_back(i);

           if(i-dq.front()>=k)
           {
            dq.pop_front();
           }

           
           


        }

        return nums[nums.size()-1];


    }
};