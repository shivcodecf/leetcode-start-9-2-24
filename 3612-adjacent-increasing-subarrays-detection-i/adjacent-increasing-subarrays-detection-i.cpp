class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        vector<int> v, v1;

        int n = nums.size(),flag=0,c=0,start=-1;

        for (int i = 0; i < nums.size(); i++) {

             flag = 0, c = 0, start = -1;

            if(c+1==k)
            {
                v.push_back(i);
                
                v.push_back(i);
                
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                
                if (nums[j] > nums[j - 1]) {

                    if (flag == 0) {
                        start = j - 1;
                    }

                    c++;

                    flag = 1;

                    if(c+1==k && flag)
                    {
                         v.push_back(start);
                         v.push_back(j);
                         break;
                    }

                } else {

                    if (flag && c + 1 == k) {
                        v.push_back(start);
                        v.push_back(j - 1);
                    }

                    break;
                }
            }


        }

        // if (flag && c+1==k) {
            
        //     v.push_back(start);
            
        //     v.push_back(n - 1);
        // }

           for(int i=0;i<v.size();i++)
            {
                cout <<v[i]<<" ";
            }

            

      

        // for (int i = 0; i < v.size(); i ++) {

        //     mp[v[i]]++;
            
        // }

          map<int,char>mp,mp1;

         for (int i = 0; i < v.size(); i ++) {

          if( i & 1)
          {
            mp1[v[i]] = 'e';
          }
          else {
            mp[v[i]] = 's';
          }


           }

           for(int i=1;i<v.size();i+=2)
           {   
           
              int x = v[i]+1;
           
            if(mp[x]=='s')
            {
                return true;
            }
            

           }

           return false;




            
        

        return false;
    }
};