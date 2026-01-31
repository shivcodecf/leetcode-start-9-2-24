class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {


        
        queue<pair<int, string>>q;

        q.push({0, beginWord});

        map<string,int>mp;

        for(int i=0;i<wordList.size();i++)
        {
            mp[wordList[i]]++;
        }
        
        vector<string>temp;
        vector<vector<string>>ans;

        int level = 0;

        temp.push_back(beginWord);

        while (!q.empty()) {
            int n = q.size();

            level++;

            while (n--) {

                auto [step, s] = q.front();

                q.pop();

                if(s == endWord)
                {
                  return step+1;
                }

                string s1 = s;

                for (int i = 0; i < s.size(); i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        s[i] = ch;

                        if(mp.find(s)!=mp.end())
                        {
                          q.push({level, s});
                          temp.push_back(s);
                          mp[s]--;

                          if(mp[s]==0)
                          {
                            mp.erase(s);
                          }
                        }     
                        
                      
                       
                    }

                    s = s1;

                    
                }
            }
        }

        return 0;


        
    }
};