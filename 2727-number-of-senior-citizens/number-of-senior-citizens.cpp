class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;

        for(int i=0;i<details.size();i++)
        {
            string s = details[i].substr(11,2);
            int check = stoi(s);

            if(check>60)
            {
                ans++;
            }
        }

        return ans;
    }
};