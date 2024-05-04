class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());

        int i=0,j=people.size()-1,ans=0;
        map<int,int>mp;


        while(i<=j)
        {
            if(i==j)
            {
                ans++;
                break;
            }
           while(people[i]+people[j]>limit && i<j)
           {
             ans++;
             j--;
           }
              ans++;
              i++;
              j--;
           

        }

        // for(int i=0;i<people.size();i++)
        // {
        //     if(mp.find(i)==mp.end())
        //     {
        //         ans++;
        //     }
        // }

        return ans;

    }
};