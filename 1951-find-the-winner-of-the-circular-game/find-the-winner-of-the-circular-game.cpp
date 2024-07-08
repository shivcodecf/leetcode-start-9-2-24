class Solution {
public:
    int findTheWinner(int n, int k) {

       queue<int>q;
       vector<int>v,v1;
       map<int,int>mp;

       for(int i=1;i<=n;i++)
       {
        q.push(i);
        v.push_back(i);
       }
       int c=0;

       if(k==1)
       {
        return n;
       }

       while(1)
       {     
         
         v1.clear();

        for(int i=0;i<v.size();i++)
        {
             c++;

            if(c%k)
            {
                v1.push_back(v[i]);
            }

        }

        v.clear();

        if(v1.size()==1)
        {
            return v1.back();
        }

        for(int i=0;i<v1.size();i++)
        {
            v.push_back(v1[i]);
        }




       }

       



    }
};