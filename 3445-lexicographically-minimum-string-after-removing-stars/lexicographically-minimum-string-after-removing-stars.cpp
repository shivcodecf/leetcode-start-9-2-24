class Solution {
public:
    string clearStars(string s) {

        using Pair = std::pair<char, int>;

         // Custom comparator for the priority queue
        auto compare = [](const Pair& a, const Pair& b) {
            if (a.first == b.first) {
                return a.second < b.second; // Sort second elements in descending order
            } else {
                return a.first > b.first; // Sort first elements in ascending order
            }
        };
        
        int n=s.size();

            map<char,int>mp;
        std::priority_queue<Pair, std::vector<Pair>, decltype(compare)> pq(compare);
           int star=0;
           map<int,int>mp1;


        for(int i=0;i<n;i++)
        {    
             

            if(s[i]!='*')
            {
                
                pq.push({s[i],i});
            }
            else {

                auto it=pq.top();

                mp1[it.second]++;

                pq.pop();


            }



            

            
        }

        string ans="";

        for(int i=n-1;i>=0;i--)
        {
            if(mp1[i]>0)
            {
                
                mp1[i]--;

                if(mp1[i]==0)
                {
                    mp1.erase(i);
                }
            }
            else  {
                if(s[i]!='*')
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;






        // for(auto it:mp)
        // {
        //     pq.push({it.first,it.second});
        // }
        // int check=star;
        // map<char,int>mp1,mp2;


        // while(pq.size())
        // {
        //    auto it= pq.top();
        //    if(star>0)
        //    {
        //     if(it.second==1)
        //     {
        //         mp1[it.first]++;
        //         star--;
        //     }
        //     else {
        //        if(star>it.second)
        //        {
        //         star-=it.second;
        //         mp2[it.first]++;
                
        //        } 
        //        else {
        //         star=0;
        //         mp2[it.first]++;
        //        }

        //     }
            
        //    }
        //    else {
        //     break;
        //    }

        //    pq.pop();




        // }

        // string ans="";
        // map<int,int>mp3;

        // for(int i=n-1;i>=0;i--)
        // {   
           
        //      if(mp2.find(s[i])!=mp2.end() )
        //      {
        //        mp3[i]++;
        //        mp2[s[i]]--;
        //        if(mp2[s[i]]==0)
        //        {
        //         mp2.erase(s[i]);
        //        }
               
        //      }

             
            

            

             

        // }
        
        // for(int i=0;i<n;i++)
        // {   
           
        //      if(mp1.find(s[i])!=mp1.end() )
        //      {
        //        mp3[i]++;
        //        mp1[s[i]]--;
        //        if(mp1[s[i]]==0)
        //        {
        //         mp1.erase(s[i]);
        //        }
               
        //      }

             
            

            

             

        // }

        // for(int i=0;i<n;i++)
        // {
        //      if(mp3.find(i)==mp3.end() && s[i]!='*')
        //      {
        //         ans+=s[i];
        //      }
        // }


        // return ans;












        
        
    }
};