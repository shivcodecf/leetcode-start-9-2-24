class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        

        sort(intervals.begin(),intervals.end());

        priority_queue<int,vector<int>,greater<int>>pq;

        int n=intervals.size(),grp=0;

        for(int i=0;i<n;i++)
        {
            if(pq.empty())
            {
               grp++;
               pq.push(intervals[i][1]);
            }
            else {
                int x = pq.top();

                if(intervals[i][0]>x)
                {
                    pq.pop();
                    pq.push(intervals[i][1]);
                }
                else {
                    grp++;
                    pq.push(intervals[i][1]);
                }
            }
        }

        return grp;

    }
};