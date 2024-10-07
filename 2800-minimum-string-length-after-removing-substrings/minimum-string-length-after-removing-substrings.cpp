class Solution {
public:
    int minLength(string s) {

        string temp="";

        if(s.size()==1) return 1;
        
        for(int i=0;i<100;i++)
        {   
             temp ="";
            int flag =0;
            for(int j=0;j<s.size()-1;j++)
            {
             
             if((s[j]=='A' && s[j+1]=='B') || (s[j]=='C' && s[j+1]=='D'))
             {
                j++;
                flag=1;
             }
             else {
                temp+=s[j];
             }

            }

            int n=s.size();
             

            if((s[n-2]=='C' && s[n-1]=='D')  ||   (s[n-2]=='A' && s[n-1]=='B'))
            {
              int flag1=0;
            }
            else {
                temp+=s[n-1];
            }

              cout <<temp<<endl;

            if(flag && temp.size()>1)
            {
                s = temp;
            }
          
            else {
                
                return temp.size();
            }



            
        }

        return -1;



    }
};