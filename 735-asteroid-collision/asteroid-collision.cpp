class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         
        int n=asteroids.size();

         stack<int>st;

         vector<int>ans;



        for(int i=n-1;i>=0;i--)
        {   

            if(asteroids[i]<0)
            { 

                st.push(abs(asteroids[i]));
                continue;
              
            }

            else if(st.empty())
            {
                ans.push_back(asteroids[i]);
            }

            else {
                int flag=0;

               while(!st.empty())
               { 

                  int x = st.top();

                  st.pop();

                  if(x==asteroids[i])
                  { 
                    flag=1;
                    break;
                  }

                  if(x>asteroids[i])
                  {
                   
                   
                    st.push(x);
                     break;
                 

                  }


                 
                 


               }

               if(st.empty() && !flag)
               {
                ans.push_back(asteroids[i]);
               }

              

            }


        }

        vector<int>v;

        while(!st.empty())
        {  
            int x = -1*st.top();
            v.push_back(x);
            st.pop();
        }

        reverse(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i]);
        }





        reverse(ans.begin(),ans.end());

        return ans;








    }
};