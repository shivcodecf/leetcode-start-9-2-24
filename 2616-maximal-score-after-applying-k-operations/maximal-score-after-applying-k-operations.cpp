class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<long long>pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        long long ans=0,c=0;

        while(pq.size())
        {
            long long x = pq.top();
            pq.pop();
            ans+=x;
            x = (x+3-1)/3;
            pq.push(x);
            c++;
            if(c==k)
            {
                break;
            }

        }

        return ans;

    }
};