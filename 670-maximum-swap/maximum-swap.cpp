class Solution {
public:
    int maximumSwap(int num) {
        

        vector<pair<char,int>>v;

        map<int,int>mp;

        string s = to_string(num);

        for(int i=0;i<s.size();i++)
        { 

            v.push_back({s[i],i});

            mp[s[i]-'0'] = max(i,mp[s[i]-'0']);

        }


         sort(v.begin(),v.end());

         reverse(v.begin(),v.end());


        for(int i=0;i<v.size();i++)
        {
            cout <<v[i].first<<" "<<v[i].second<<endl;
        }

        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=v[i].first)
            {  
                char temp = s[i];

                s[i] = v[i].first;

                int ind = mp[v[i].first-'0'];

                s[ind] = temp;

                break;


            }
        }

        int ans = stoi(s);

        return ans;



       
    }
};