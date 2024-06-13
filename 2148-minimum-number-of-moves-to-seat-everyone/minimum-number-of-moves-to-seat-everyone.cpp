class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

       map<int,int>mp,mp1,mp2; 

       int n=seats.size(),m=students.size();

       for(int i=0;i<n;i++)
       {
        mp[seats[i]]++;
       }
       for(int i=0;i<m;i++)
       {
        mp2[students[i]]++;
       }

       sort(seats.begin(),seats.end());

       sort(students.begin(),students.end());

       int j=0,ans=0;

        

       for(int i=0;i<m;i++)
       {     



           if(mp[students[i]]>0)
           { 
            mp[students[i]]--;
            continue;
           }
             

             while(j<n)
            { 



                if(mp2[seats[j]]>0 )
                {
                    mp2[seats[j]]--;
                    j++;
                   
                    continue;
                    
                }
                else {
                    ans+=abs(students[i]-seats[j]);
                    j++;
                    break;
                }
               

               
                
            


            }


       }

       return ans;
       


    }
};