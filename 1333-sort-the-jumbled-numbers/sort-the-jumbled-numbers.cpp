    #include<bits/stdc++.h>
    using namespace std;


class Solution {
public:

    
    
    
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        map<int,int>mp,mp1;
        int n=nums.size();

        vector<pair<int,pair<int,int>>>v;

        auto customOperator = [] (const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>&b )
        { 

           if(a.second.first==b.second.first)
           {
             return a.second.second < b.second.second;
           }

           return a.first < b.first;
        };
       
       
       for(int i=0;i<nums.size();i++)
       { 


         int x= nums[i];
         int prev = nums[i];
         string s= "";

         while(x>0)
         {
            int y= x%10;
            mp[y]= mapping[y];
            x= x/10;

            s+= mp[y]+'0';
         }



        

         if(s.size()==0)
         {
            nums[i] = mapping[0];
         }

         else {
             reverse(s.begin(),s.end());
             nums[i] = stoi(s);
         }



        

         

        //  mp1[stoi(s)] = prev;

        

         v.push_back({nums[i],{prev,i}});





       }



       sort(nums.begin(),nums.end());

       sort(v.begin(),v.end(),customOperator);


       vector<int>ans;

       for(int i=0;i<v.size();i++)
       {
        cout <<v[i].second.first<<" ";
       }



       for(int i=0;i<n;i++)
       {
         nums[i] = v[i].second.first;
       }

       return nums;





    //   cout <<nums[0];
      







       
    }
};