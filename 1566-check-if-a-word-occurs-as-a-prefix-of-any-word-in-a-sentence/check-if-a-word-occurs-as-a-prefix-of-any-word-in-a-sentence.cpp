class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n=sentence.size();

        string s1="";

        vector<string>v;

        for(int i=0;i<n;i++)
        {
            if(sentence[i]!=' ')
            {
                s1+=sentence[i];
            }
            else {
                v.push_back(s1);
                s1="";            }
        }

        v.push_back(s1);

        int x = searchWord.size();

        for(int i=0;i<v.size();i++)
        {
             string s1 = v[i].substr(0,x);

             if(s1==searchWord)
             {
                return i+1;
             }
        }

        return -1;



    }
};