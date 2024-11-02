class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        int n=sentence.size();

        vector<string>v;

        string s="";

        for(int i=0;i<n;i++)
        {
           if(sentence[i]!=' ')
           {
            s+=sentence[i];
           }
           else {
              v.push_back(s);
              s="";
           }
        }

        v.push_back(s);

        for(int i=0;i<v.size();i++)
        {
            cout <<v[i]<<" ";
        }

        for(int i=1;i<v.size();i++)
        {  
            int x = v[i-1].size();

          

            char ch = v[i-1][x-1];

            char ch1 = v[i][0];

            if(ch!=ch1)
            {
                return false;
            }

            


        }

        int l = v.size();
        int last = v[l-1].size();


        if(v[l-1][last-1]!=v[0][0])
        {
            return false;
        }

        return true;

      







    }
};