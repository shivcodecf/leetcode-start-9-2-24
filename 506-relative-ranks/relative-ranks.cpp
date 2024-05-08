class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        vector<string>answer(score.size(),"");
        int c=0;
        while(!pq.empty())
        {  
                 c++;
                 if(c==1)
                 {
                     answer[pq.top().second]="Gold Medal";
                 }
                  else if(c==2)
                 {
                     answer[pq.top().second]="Silver Medal";
                 }
                else if(c==3)
                 {
                     answer[pq.top().second]="Bronze Medal";
                 }
                 else
                 {
                    answer[pq.top().second]=to_string(c);
                 }
           
           
                pq.pop();

        }
     return answer;
        

    }
};