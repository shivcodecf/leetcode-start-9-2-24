#define pi pair<int, int>

class Solution {
public:  

    bool isNStraightHand(vector<int>& hand, int groupSize) {

      
      

      map<int,int>mp;

      int n=hand.size();

      if(n % groupSize!=0)
      {
        return false;
      }

      for(int i=0;i<n;i++)
      {
        mp[hand[i]]++;
      }

      priority_queue<pi, vector<pi>, greater<pi> > pq;

      vector<int>ans;

      vector<pair<int,int>>v; 

      for(auto i:mp)
      {
        pq.push({i.first,i.second});
      }

      int check=0;

      while(!pq.empty())
      {  

         check++;

        auto it= pq.top();

        int x=it.first;

        int y=it.second;

        ans.push_back(x);

        

        y--;

        
        if(y>0)
        {
            v.push_back({x,y});
        }

        pq.pop();


        if(check == groupSize)
        {  


          for(int j=0;j<v.size();j++)
          {
            pq.push({v[j].first,v[j].second});
          }

           v.clear();
           check=0;

        }


      }
      int c=0;
      if(ans.size() % groupSize!=0)
      {
        return false;
      }

      for(int i=1;i<ans.size();i++)
      {   
          c++;

         if(ans[i]-ans[i-1]!=1 && c<=groupSize-1)
         {
            return false;
         }

         if(c==groupSize)
         {
            c=0;
         }

         
      }

      return true;



















    }
};