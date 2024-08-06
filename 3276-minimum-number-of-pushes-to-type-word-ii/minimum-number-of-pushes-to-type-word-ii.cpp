class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        
        // mp['a'] = 1;
        // mp['f'] = 2;
        // mp['g'] = 3;
        // mp['b'] = 1;
        // mp['h'] = 2;
        //  mp['i'] = 3;
        //   mp['c'] = 1;
        //    mp['j'] = 2;
        //     mp['k'] = 3;
        //     mp['d'] = 1;
        //      mp['l'] = 2;
        //       mp['m'] = 3;
        //        mp['e'] = 1;
        //         mp['n'] = 2;
        //          mp['o'] = 3;
        //            mp['p'] = 1;
        //              mp['q'] = 2;
        //                mp['r'] = 3;
        //                mp['s'] = 4;
        //                mp['t'] = 1;
        //                mp['u'] = 2;
        //                mp['v'] = 3;

        //                 mp['w'] = 1;
        //                  mp['x'] = 2;
        //                   mp['y'] = 3;
        //                    mp['z'] = 4;

                           long long ans=0;

                           for(int i=0;i<word.size();i++)
                           {
                             mp[word[i]]++;
                           }

                           long long cnt=0;

                           vector<int>v;

                           for(auto i:mp)
                           {
                             v.push_back(i.second);
                           }

                           sort(v.begin(),v.end());

                            reverse(v.begin(),v.end());
                            long long sum=1;

                            for(int i=0;i<v.size();i++)
                            {
                                cnt++;
                               
                                ans+=v[i]*sum;

                                 if(cnt%8==0)
                                {
                                   sum++;
                                }
                            }

                           return ans;




    }
};