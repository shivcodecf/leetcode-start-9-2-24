class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<pair<string,string>> v;

        map<string, int> mp;

        mp["restaurant"]++;

        mp["grocery"]++;

        mp["pharmacy"]++;

        mp["electronics"]++;

        for (int i = 0; i < code.size(); i++) {

            int flag = 0;

            for (int j = 0; j < code[i].size(); j++) {

                if (isalpha(code[i][j]) || code[i][j] == '_' ||
                    isdigit(code[i][j])) {

                    continue;

                }

                else {

                     flag = 1;

                     break;
                }
            }

            if (flag == 0 && mp.find(businessLine[i]) != mp.end() &&
                isActive[i] == true && code[i]!="") {
                v.push_back({businessLine[i],code[i]});
            }
        }



        sort(v.begin(), v.end());

        vector<string>ans;

        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].second);
        }

        return ans;

        
    }
};