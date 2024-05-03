class Solution {
public:
    int compareVersion(string version1, string version2) {

     
     vector<int>v1,v2;
     int n=version1.size(),m=version2.size();
     int flag=0;
     string temp="";
     int res1=0;

     for(int i=0;i<n;i++)
     {  

        if(version1[i]=='0' && !flag)
        {   

            continue;

            
        }
        else { 

            flag=1;
            if(version1[i]!='.')
            {
               
              temp+=version1[i];
            }
            else{
                if(temp.size()){
                res1=stoi(temp);
                v1.push_back(res1);
                }
                else {
                    v1.push_back(0);
                }
               
                temp="";
                flag=0;


            }
           


        }

     }
       if(temp.size())
       {
         res1=stoi(temp);
         v1.push_back(res1);
       }
     
      temp="";

     for(int i=0;i<m;i++)
     {  

        if(version2[i]=='0' && !flag)
        {   

            continue;

            
        }
        else { 

            flag=1;
            if(version2[i]!='.')
            {
               
              temp+=version2[i];
            }
            else{
                if(temp.size())
                {
                   res1=stoi(temp);
                   v2.push_back(res1);
                }
                else {
                    v2.push_back(0);
                }
               
                
                temp="";
                flag=0;
            }
           


        }

     }
     if(temp.size())
     {
      res1=stoi(temp);
      v2.push_back(res1);
     }

     
     int l=min(v1.size(),v2.size());
     int l1=max(v1.size(),v2.size());
     if(v1.size()>v2.size())
     {
        int l2=v1.size()-v2.size();

        for(int i=0;i<l2;i++)
        {
            v2.push_back(0);
        }
     }
     else {
        int l2=v2.size()-v1.size();

        for(int i=0;i<l2;i++)
        {
            v1.push_back(0);
        }
     }

    
     for(int i=0;i<v1.size();i++)
     {
        if(v1[i]>v2[i])
        {
            return 1;
        }
        else if(v1[i]<v2[i])
        {
            return -1;
        }
     }
     
     return 0;


    //  else {
    //     if(v1.size()>v2.size())
    //     {
    //         return 1;
    //     }
    //     else {
    //         return -1;
    //     }
    //  }




     

     








    }
};