class Solution {
public:
    bool canChange(string start, string target) {

        int j = 0;

        int m = start.size();

        int n=target.size();

       

        vector<int>v;

        int c1=0,c2=0;

        for(int i=0;i<n;i++)
        {
          if(target[i]!='_')
          {
            c1++;
          }
        }

        for(int i=0;i<m;i++)
        {
          if(start[i]!='_')
          {
            c2++;
          }
        }

        if(c1!=c2)
        {
            return false;
        }

        int i=0;

        for ( i = 0; i < target.size(); i++) {

            if (target[i] != '_') {

                

                while (j < m && start[j] == '_') {

                    j++;
                }

                cout <<j<<" ";

                if (target[i] == 'L' && start[j] == 'L') {
                    if (i > j) {
                        return false;
                    }
                } else if (target[i] == 'R' && start[j] == 'R') {
                    if (j > i) {
                        return false;
                    }
                }

                else if (start[j] != target[i]) {
                    return false;
                }

                j++;
            }

           


        }

       

        // for(int i=0;i<v.size();i++)
        // {
        //     cout <<v[i]<<" ";
        // }

        

        return true;

        

    }
};