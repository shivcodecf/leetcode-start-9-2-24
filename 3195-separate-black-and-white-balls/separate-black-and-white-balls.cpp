class Solution {
public:
    long long minimumSteps(string s) {

        long long start = 0,flag=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {  
                flag=1;
                start = i;
                break;
            }
        }

        if(flag==0)
        {
            return 0;
        }

        long long ans=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0' && i>start)
            {
                ans+=i-start;
                start++;
            }
        }

        return ans;

    }
};