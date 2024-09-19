class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        

        int n=exp.size();

        bool flag=false;

        vector<int>res;

        for(int i=0;i<n;i++)
        {   
            if(!isdigit(exp[i]))
            {
                 flag = true;

                 vector<int>left= diffWaysToCompute(exp.substr(0,i));
                 vector<int>right= diffWaysToCompute(exp.substr(i+1));


                 for(int j=0;j<left.size();j++)
                 {
                    for(int k=0;k<right.size();k++)
                    {
                        if(exp[i]=='+')
                        {
                             res.push_back(left[j]+right[k]);
                        }
                        else if(exp[i]=='-')
                        {
                             res.push_back(left[j]-right[k]);
                        }
                        else {
                             res.push_back(left[j]*right[k]);
                        }
                    }
                 }

            }


        }

        if(res.size()==0)
        {
            res.push_back(stoi(exp));
        }

        return res;
    }
};