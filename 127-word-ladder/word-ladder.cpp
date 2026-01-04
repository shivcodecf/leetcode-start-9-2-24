class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        map<string, int> mp;

        for (int i = 0; i < wordList.size(); i++) {
            
            mp[wordList[i]]++;
        }

        queue<pair<string, int>> q;

        if(mp.find(endWord)==mp.end())
        {
            return 0;
        }

        q.push({beginWord,0});

        int ans = 0;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                string s = q.front().first;
                int l = q.front().second;
                q.pop();

                string s1 = s;

                if(s==endWord)
                {
                    return l+1;
                }

               

                int flag = 0;

                for (int i = 0; i < s1.size(); i++) {

                    for (char j = 'a'; j <= 'z'; j++) {

                        s[i] = j;

                        if(mp.find(s)!=mp.end())
                        {  
                            flag = 1;
                            q.push({s,l+1});
                            mp.erase(s);
                        }

                        s = s1;


                    }
                }

               

            }


        }

        return 0;

        
    }
};