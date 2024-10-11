class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n=times.size();

        int cnt=-1;

        map<int,int>mp1,mp2,mp4;

        int check = times[targetFriend][0];

         cout <<check<<endl;

        for(int i=0;i<times.size();i++)
        {
            mp1[times[i][0]]++;

            mp4[times[i][0]] = times[i][1];
        }

        for(int i=0;i<times.size();i++)
        {
            mp2[times[i][1]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        map<int,vector<int>>mp3;

        

        for(int i=1;i<=1e5;i++)
        {    
           
          

            if(mp3.find(i)!=mp3.end()) {
                
              for(auto it:mp3[i])
              {
                pq.push(it);
              }

             

           }

            if(i==check)
           {
             
             if(pq.size())
             { 

                return pq.top();

             }
             else {

                cnt++;

                return  cnt;
             }

           }



           if(mp1.find(i)!=mp1.end())
           { 

            if(pq.empty())
            {
                 cnt++;

                 int x  = mp4[i];

                 mp3[x].push_back(cnt);
                
            }

            else {
              
              int x = pq.top();

              pq.pop();

              int y = mp4[i];

              mp3[y].push_back(x);
             
            }
           
           }

           


        }

       

        return -1;

        


    }
};