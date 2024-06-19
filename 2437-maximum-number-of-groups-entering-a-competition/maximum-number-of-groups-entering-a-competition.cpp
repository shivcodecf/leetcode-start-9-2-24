class Solution {
public:
    int maximumGroups(vector<int>& grades) {

      int sum=0,n=grades.size();

    //   sort(grades.begin(),grades.end());

    //   vector<int>v1,v;
    //   for(int i=0;i<n;i++)
    //   {
    //     sum+=grades[i];
    //     v.push_back(sum);
    //   }

    //   sum=0;

    //     for(int n-1=0;i>=0;i--)
    //   {
    //     sum+=grades[i];
    //     v1.push_back(sum);
    //   }

      int c=1,ans=0;

      while(sum<n)
      { 
        
        sum+=c;
       
        if(sum<=n)
        {
           ans++;
        }

         c++;
       
        
      }

      return ans;



     

    }
};