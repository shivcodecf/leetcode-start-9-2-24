class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
    
    int mini=intervals[0][0];
    int maxi=intervals[0][1];

    int prev=intervals[0][1];
    int n=intervals.size();
    vector<vector<int>>v;
     vector<int>temp;  

     if(n==1)
     {
        temp.push_back(mini);
        temp.push_back(maxi);
        v.push_back(temp);
        return v;
     }
   

    for(int i=1;i<n;i++)
    {    
       
        
        if(prev>=intervals[i][0])
        {
         maxi=max(maxi,intervals[i][1]);
         mini=min(mini,intervals[i][0]);
         prev=max(prev,intervals[i][1]);

        }
        else{
            temp.push_back(mini);
            temp.push_back(maxi);
            v.push_back(temp);
               maxi=intervals[i][1];
               mini=intervals[i][0];
               prev=intervals[i][1];
               temp.clear();
        } 
        
        if(i==n-1 )
        {     
           
            temp.push_back(mini);
            temp.push_back(maxi);
            v.push_back(temp);
        }
         

    }
   
    return v;



    }
};