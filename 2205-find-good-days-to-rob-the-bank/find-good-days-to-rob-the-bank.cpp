class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
     int n=security.size();

     vector<int>pref(n,0),pref1(n,0);

     pref[0]= 0;

     for(int i=1;i<n;i++)
     {
        if(security[i]>=security[i-1])
        {
            pref[i] = pref[i-1]+1;
        }
        else {
            pref[i] = 0;
        }
     }

     pref1[0] = 0;

     for(int i=n-2;i>=0;i--)
     {
        if(security[i]>=security[i+1])
        {
            pref1[i] = pref1[i+1]+1;
        }
        else {
            pref1[i] = 0;
        }
     }

     vector<int>v;

     for(int i=0;i<n;i++)
     {  

        int left = i-(time);

        int right = i+(time);

        if(left>=0 && right<n)
        {
            if(pref1[left]-pref1[i]==time  && pref[right]-pref[i]==time)
            {
               v.push_back(i);
            }
        }

     }

     for(int i=0;i<n;i++)
     {
        cout <<pref1[i]<<" ";
     }

     return v;








    
















    }
};