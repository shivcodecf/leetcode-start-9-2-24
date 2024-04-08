#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        for (int i = 0; i < n; ++i)
            q.push(students[i]);
        
        
        for (int i = 0; i < sandwiches.size(); ++i) {
            int currentSandwich = sandwiches[i];
            int originalSize = q.size(); 
            for(int j=0;j<originalSize;j++)
            {      
                int front=q.front();
               
              if( front != currentSandwich ) {
               q.push(front);
                 q.pop();
              
               }
               else {
                  q.pop();
                break;
               }

            }
           if(originalSize == q.size())
           {
            return originalSize;
           }
        }
        
        return 0; // All sandwiches served
    }
};
