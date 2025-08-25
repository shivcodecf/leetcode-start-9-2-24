class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        if (nums.size() % k) {
            return false;
        }

        priority_queue<pair<int,int>> pq;

        

        for (auto it : mp) {

            pq.push({it.second,it.first});

        }

        

        while (!pq.empty()) {

            int l = pq.size();

            if (k > l ) {
                return false;
            }

            int l1 = k;

            map<int,int>mp1;

            vector<pair<int,int>>v;

            int c=0;

            while(c<k)
            {  

                if(pq.empty())
                {
                    return false;
                }

                int x = pq.top().first; // freq

                int y = pq.top().second; // number

                pq.pop();

                if(mp1[y])
                {
                 v.push_back({x,y});
                 continue;
                }

                mp1[y]++;

                x--;

                c++;

                if(x>0)
                {
                    pq.push({x,y});
                }

                
            }


            for(int i=0;i<v.size();i++)
            {
                pq.push({v[i].first,v[i].second});
            }


        }

      
        return true;



    }
};