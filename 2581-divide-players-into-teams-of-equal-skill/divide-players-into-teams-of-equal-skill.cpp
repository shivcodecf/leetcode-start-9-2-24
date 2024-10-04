class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        
        sort(skills.begin(),skills.end());

        int i=0,j=skills.size()-1;
        map<int,int>mp;

        long long check =0,ans=0;

        while(i<j)
        {
             check = skills[i]*skills[j];
             ans+=check;

             long long sum = skills[i]+skills[j];

            mp[sum]++;

            i++;
            j--;

        }

        return mp.size()==1 ? ans : -1;


    }
};