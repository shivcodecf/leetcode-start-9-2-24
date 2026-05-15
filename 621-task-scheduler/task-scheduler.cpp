class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        //  A -> 3 , B -> 3

        // A _ _ A _ _ A

        // 6 + 2 = 8

        int space = 0;

        map<char, int> mp;

        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }

        int maxi = INT_MIN, maxElement = -1;

        for (auto it : mp) {
            if (it.second > maxi) {
                maxi = max(maxi, it.second);
                maxElement = it.first;
            }
        }

        int block = maxi-1;

        space = (maxi-1)*n; 

        for (auto it : mp) {

            if(it.first !=maxElement)
            {
                space-=min(block,it.second);
            }
        }

        if(space>=0)
        {
            return space+tasks.size();
        }

        return tasks.size();
    }
};