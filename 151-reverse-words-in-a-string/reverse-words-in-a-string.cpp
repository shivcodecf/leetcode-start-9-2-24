class Solution {
public:
    string reverseWords(string s) {

        vector<string>v;

        string s1="";

        int flag = 0;


        for(int i=0;i<s.size();i++)
        { 



          if(s[i]!=' ')
          {
             s1+=s[i];
            
          }

          else {
               
            
             if(s1.size()>0)
             {
                v.push_back(s1);

                s1 = "";
             }


          }



        }

        if(s1.size())

        v.push_back(s1);




        reverse(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
            cout <<v[i]<<" ";
        }

        string ans = "";

        for(int i=0;i<v.size();i++)
        {   
            
           
            ans+=v[i];

            if(i!=v.size()-1)
            {

                 ans+=" ";

            }
           
        }

        return ans;
        

    }
};