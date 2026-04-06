class Solution {
public:
    int mirrorFrequency(string s) {

        map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        // int ans = 0;

        // char ch = 'c';

        // // a -> z  , b -> y , c -> x

        // int x = ch - 'a';

        // char ch1 = 'z' - x;

        // cout << ch << " " << ch1 << endl;

        // return 2;

        // char ch = '1';

        // int ch1 = 9 - ch;

        // cout << ch << " " << ch1 << endl;

        // cout << mp.size() << endl;

        map<char, int> mp1;

        int ans = 0;

        for (auto it : mp) {

            if (mp1.find(it.first) == mp1.end()) {
                if (isalpha(it.first)) {
                    char ch = it.first;

                    char ch1 = 'z' - (ch - 'a');

                    // cout <<ch<<" "<<ch1<<" "<<ans<<endl;;

                    // cout << "freq" << " " << mp[ch] << " " << mp[ch1] <<
                    // endl;

                    ans += abs(mp[ch] - mp[ch1]);

                    mp1[ch]++;

                    mp1[ch1]++;
                } else {

                    int x = it.first - '0';

                    int y = 9 - x;

                    char ch = x + '0';
                    char ch1 = y + '0';

                    cout << "freq" << mp[ch] << " " << mp[ch1] << endl;

                    ans += abs(mp[ch] - mp[ch1]);

                    mp1[ch]++;
                    mp1[ch1]++;
                }
            }
        }

        return ans;
    }
};