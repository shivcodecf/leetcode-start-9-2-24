class Solution {
public: 

    
     vector<int>v;
    int maxVowels(string s, int k) {
       int maxi=-1,ans=0,c=0,x=0;
       map<char,int>mp;
       mp['a']++;
       mp['i']++;
       mp['e']++;
       mp['o']++;
       mp['u']++;


        
        for(int i=0;i<s.size();i++)
        {    
             c++;  
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u')
            {
                ans++;
            }
            if(c==k)
            {  
                x=i;
                break;
            }
        }
        maxi=max(maxi,ans);
        int i=1,j=x+1,check=0;

        while(j<s.size())
        {   
            
              if(mp.find(s[i-1])!=mp.end())
            {
                
                
                ans--;
                
            }
            
            if(mp.find(s[j])!=mp.end())
            {
                ans++;
            }
            j++;
            i++;

            

           
           
             maxi=max(maxi,ans);
           
            
        }
        return maxi;






     
    
     


    }
};