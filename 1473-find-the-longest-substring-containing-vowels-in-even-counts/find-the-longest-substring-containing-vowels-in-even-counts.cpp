class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        map<char,int>mp;

        string vowel ="00000";

        map<string,int>mp1;

        mp1[vowel] =-1;

        int ans=0;

        cout <<vowel<<endl;



        for(int i=0;i<s.size();i++)
        {     


            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                mp[s[i]]++;

            }

            int x = mp[s[i]];

            int y = x%2;

            if(s[i]=='a')
            {
                vowel[0] = y+'0';
            }
            else if(s[i]=='e'){
              vowel[1] = y+'0';
            }
             else if(s[i]=='i'){
              vowel[2] = y+'0';
            }
             else if(s[i]=='o'){
              vowel[3] =y+'0';
            }
             else if(s[i]=='u'){
              vowel[4] =y+'0';
            }

            cout <<vowel<<" ";


            if(mp1.find(vowel)!=mp1.end())
            { 

                int len = i-mp1[vowel];

                ans=max(ans,len);


            }

            else {
                 mp1[vowel] = i;
            }
            
        }

        // cout <<vowel<<endl;

        return ans;

    }
};