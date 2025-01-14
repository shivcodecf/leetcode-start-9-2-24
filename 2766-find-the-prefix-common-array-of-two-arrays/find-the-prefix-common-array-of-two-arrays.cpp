class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        map<int,int>mp,mp1;

        vector<int>ans;

        int sum=0;
        

        for(int i=0;i<A.size();i++)
        { 
         

         mp[A[i]]++;
         mp1[B[i]]++;

         sum=0;

         for(auto it:mp)
         {
            if(mp1[it.first]>=1)
            {
                sum++;
            }
         }

         ans.push_back(sum);



    
        }

        return ans;

    }
};