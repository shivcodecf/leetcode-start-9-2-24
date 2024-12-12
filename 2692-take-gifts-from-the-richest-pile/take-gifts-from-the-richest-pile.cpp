class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int>pq;

        for(int i=0;i<gifts.size();i++)
        {
            pq.push(gifts[i]);
        }

        int c=0;

        while(!pq.empty())
        { 

          int x = pq.top();

          pq.pop();

          int y   =    sqrt(x);

          float z =   sqrt(x);


          c++;

          pq.push(y);

       

          if(c==k)
          {
            break;
          }



        }

        long long ans=0;

        while(!pq.empty())
        { 

            ans+=pq.top();

            pq.pop();

        }

        return ans;

    }
};