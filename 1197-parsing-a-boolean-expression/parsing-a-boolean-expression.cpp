class Solution {
public: 

   bool helper(string& expression,int& idx)
   {
    if(expression[idx]=='t')
    {  
        idx++;
        return true;
    }

    // else if(expression[idx]=='f')
    // {
    //     idx++;
    //     return false;
    // }
   
    if(expression[idx]=='!')
    {
        idx+=2;
        bool res = helper(expression,idx);

        idx++;

        return !res;
    }

    else if(expression[idx]=='&')
    {
        bool res = true;
        idx+=2;
        while(expression[idx]!=')')
        {
            if(expression[idx]==',')
            {
                idx++;
            }
            else{
                bool temp = helper(expression,idx);

                res = res&temp;
            }
        }
        idx++;
        return res;
    }

    else if(expression[idx]=='|')
    {
        bool res = false;
        idx+=2;
        while(expression[idx]!=')')
        {
            if(expression[idx]==',')
            {
                idx++;
            }
            else{
                bool temp = helper(expression,idx);

                res = res|temp;
            }
        }
        idx++;
        return res;
    }

    idx++;
    return false;


   }
    bool parseBoolExpr(string expression) {
        
      int idx=0;

      return helper(expression,idx);


    }
};