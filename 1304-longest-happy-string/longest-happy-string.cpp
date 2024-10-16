class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
      

        string ans="";

        // int c1=0,c2=0,c3=0;

        // vector<pair<int,char>>v;

        //  v.push_back({a,'a'});

        //  v.push_back({b,'b'});

        //  v.push_back({c,'c'});

        //   sort(v.begin(),v.end());

        //   reverse(v.begin(),v.end());

        //    char ch1 = v[0].second;

        //    int x = v[0].first;

        //    char ch2 = v[1].second;
           
        //    int y= v[1].first;

        //    char ch3 = v[2].second;

        //    int z = v[2].first;

          

           priority_queue<pair<int,char>>pq;
             
             if(a>0)
             pq.push({a,'a'});
             if(b>0)
             pq.push({b,'b'});
             if(c>0)
             pq.push({c,'c'});

              char check = 'z';

             vector<pair<int,char>>v1;

             while(!pq.empty())
             { 

              auto it = pq.top();

               pq.pop();

              int x1= it.first;

              char ch5 = it.second;

             

            

            

              if(check==ch5)
              {  

                 

                v1.push_back({x1,ch5});

                if(pq.empty())
                {
                    break;
                }
               
                 int x = pq.top().first;

                 char ch = pq.top().second;

                 pq.pop();
                 
                    if(v1.size()>=1)
                 {
                    pq.push({v1.back().first,v1.back().second});

                    v1.pop_back();
                 }

               
               
             

             

              ans+=ch;

              x = x-1;

               if(x>0)
              {
                pq.push({x,ch});
              }

              if(ans.size()>=2)
              { 
                int siz = ans.size()-2;
                string s4 = ans.substr(siz,2);

                if(s4=="aa" || s4=="bb" || s4=="cc")
                {
                    check = ch;
                }
                else {
                    check = 'z';
                }
                
              }
              else {
                check = 'z';
              }

             

            
             

              


              }

             
              else {


              int x = x1;

              char ch = ch5;

             

             
              ans+=ch;

              x--;

              if(x>0)
              {  
                pq.push({x,ch});
               

              }

              if(ans.size()>=2)
              { 
                int siz = ans.size()-2;
                string s4 = ans.substr(siz,2);

                if(s4=="aa" || s4=="bb" || s4=="cc")
                {
                    check = ch;
                }
                else {
                    check = 'z';
                }
                
              }

              else {
                check = 'z';
              }

              


              }
             

             

            

             

             }

             return ans;



        

    //    while(x>0 || y>0 || z>0)
    //    { 

    //      if(x>0 && c1<2)
    //      {
    //         ans+=ch1;
    //         c1++;
    //         x--;
    //         c2=0;
    //         c3=0;
    //      }

    //      else if(y>0 && c2<2)
    //      {
    //         ans+=ch2;
    //         y--;
    //         c2++;
    //         c1=0;
    //         c3=0;
    //      }

    //      else if(z>0 && c3<2)
    //      {
    //       ans+=ch3;
    //       z--;
    //       c3++;
    //       c1=0;
    //       c2=0;
    //      }
    //      else {
    //         break;
    //      }


    //    }

    //    return ans;

    }
};