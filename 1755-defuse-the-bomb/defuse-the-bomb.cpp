class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n=code.size();
        

        vector<int>pref(2*n);

        int sum=0;

        vector<int>ans,v;

        for(int i=0;i<n;i++)
        {
           v.push_back(code[i]);
        }

         for(int i=0;i<n;i++)
        {
           v.push_back(code[i]);
        }


        pref[0] = v[0];

        for(int i=1;i<v.size();i++)
        {
           pref[i] = pref[i-1]+v[i];
        }
        
        int c=0,j=0;

        for(int i=n;i<v.size();i++)
        {  
            c++;
          if(k>0)
          {
            int x = pref[j+k]-pref[j];
            ans.push_back(x);
          }
          else if(k<0)
          {
            int x = pref[i]-pref[i-abs(k)-1];
            int left = x-code[i%n];

             ans.push_back(left);
          }
          else {
            ans.push_back(0);
          }

          if(c==n)
          {
            break;
          }

          j++;
        }

        return ans;







        











       

       


    }
};