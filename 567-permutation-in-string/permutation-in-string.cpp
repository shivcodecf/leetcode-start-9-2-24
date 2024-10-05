class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        sort(s1.begin(),s1.end());

        if(s1.size()>s2.size()) return false;
        
        for(int i=0;i<=s2.size()-s1.size();i++)
        {
            string s3 = s2.substr(i,s1.size());

            sort(s3.begin(),s3.end());

            if(s3==s1)
            {
                return true;
            }
        }

        return false;

    }
};