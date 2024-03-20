class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) { 

    

       map<int,int>mp;
       int n=hand.size();
       for(int i=0;i<n;i++)
       {
        mp[hand[i]]++;
       } 
       if(hand.size()%groupSize)
       {
        return false;
       }
       
       priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(auto i:mp)
        {
            pq.push({i.first,i.second});
        } 
        vector<pair<int,int>>temp;
       
        vector<int>v1;
        int check=0,count=0;


        while(pq.size())
        {  
            
              auto it=pq.top();
          
              int f=it.first;
              int s=it.second;
              pq.pop();

            if(v1.size()==0)
            {   
                  
                v1.push_back(f);
            
                s=s-1;
               
                if(s>0)
                {    
                    temp.push_back({f,s});
                   
                }
               
            }

            else {
                
              if(v1.back()+1==f)
              { 

                v1.push_back(f);
                 s=s-1; 
                 
                
               
                if(s>0)
                {
                   
                     temp.push_back({f,s});
                     
                }

              }
              else {
                return false;
              }

            }
            if(v1.size()==groupSize  )
            {
                for(int i=0;i<temp.size();i++)
                {
                    pq.push({temp[i].first,temp[i].second});
                }
                 temp.clear();
                 v1.clear();
                 
                
                
            }








            
        }   
        if(v1.size())
        return false;


       
        
        return true;

        

    }
};