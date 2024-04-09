class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        

        queue<pair<int,int>>q;
       
       int n=tickets.size();

        for(int i=0;i<n;i++)
        {
            q.push({tickets[i],i});
        }
          int ans=0;

          while(q.size())
          {  
             int x=q.front().first;  
             int y=q.front().second;
              x=x-1;
              
             ans++;
             if(y==k && x==0)
             {
                return ans;
             }
             q.pop();
             if(x>0){
             q.push({x,y});
             }
            

          }
          return -1;



    }
};