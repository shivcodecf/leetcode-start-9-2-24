class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
      
        int n=positions.size();
       
       stack<pair<int,int>>st;

       vector<pair<int,pair<int,pair<char,int>>>>v;

       vector<pair<int,int>>ans;

       for(int i=0;i<n;i++)
       { 
        

        v.push_back({positions[i],{healths[i],{directions[i],i}}});


       }
        // int first = element.first;
        // int second_first = element.second.first;
        // char third_first = element.second.second.first;
        // int third_second = element.second.second.second;

       

       sort(v.begin(),v.end());

       for(int i=0;i<v.size();i++)
       {  


        if(v[i].second.second.first=='R')
        {
            st.push({v[i].second.first,v[i].second.second.second});
        }

        else if(v[i].second.second.first=='L')
        {    
            int x=0,diff=0,y=v[i].second.first,flag=0,y1=v[i].second.second.second;

             while(!st.empty())
             {
                 x = st.top().first;
                 int x1= st.top().second;
                
                 if(x==y)
                 {
                    flag=1;
                    st.pop();
                    break;


                 }

                else if(y<x)
                {  
                  flag=1;
                  st.pop();
                  st.push({x-1,x1});
                  break;
                }
                else {
                   st.pop();
                   diff = y-1;

                   y = diff;

                }

             }

             if(!flag)

             ans.push_back({y1,y});




        }


       }

       while(!st.empty())
       {
        ans.push_back({st.top().second,st.top().first});
        st.pop();
       }

       sort(ans.begin(),ans.end());

       vector<int>res;

       for(int i=0;i<ans.size();i++)
       {
        res.push_back(ans[i].second);
       }

       return res;

    }
};