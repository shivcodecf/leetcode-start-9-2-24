class Solution {
public:
    int maxDistance(string moves) {

        int n = moves.size();

        map<char, int> mp;
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if(moves[i]!='_'){

             mp[moves[i]]++;

            }
            else {
              cnt++;
            }
            
        }

        if(mp.size()==0)
        {
            return cnt;
        }

        int mx = 0;
        char ch;

        for (auto it : mp) {
            if (it.second > mx) {
                mx = it.second;
                ch = it.first;
            }
        }

        cout <<ch<<endl;

        // int temp = 0;

        // if(ch == 'L')
        // {

        // }

        // for(auto it:mp)
        // {
        //     if()
        // }

        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {

            if (moves[i] == 'L') {
                x--;
            } else if (moves[i] == 'R') {
                x++;
            } else if (moves[i] == 'U') {
                y++;
            } else if (moves[i] == 'D') {
                y--;
            } else {
                // int x1 = x, y1 = y, x2 = x, y2 = y, x3 = x, y3 = y, x4 = x,
                //     y4 = y;
                // x1++;
                // y1++;
                // x2--;
                // y2--;

                // int a = x1 + x;

                // int b = y1 + x;

                // int c = abs(x2) + y;

                // int d = abs(y2) + x;

                // int maxi = max({a, b, c, d});

                // if (maxi == a && mp.) {
                //     x++;
                // } else if (maxi == b) {
                //     y++;
                // } else if (maxi == c) {
                //     x--;
                // } else {
                //     y--;
                // }

                if (ch == 'R') {
                    x++;
                } else if (ch == 'U') {
                    y++;
                } else if (ch == 'L') {
                    x--;
                } else {
                    y--;
                }
            }
        }

        return abs(x) + abs(y);
    }
};