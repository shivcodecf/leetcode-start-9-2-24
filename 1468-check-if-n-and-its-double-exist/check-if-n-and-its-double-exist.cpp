class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        map<int,int>mp;

        int z=0;

        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;

            if(arr[i]==0)
            {
                z++;
            }
        }

        for(int i=0;i<arr.size();i++)
        {  

            
            
            if(mp.find(arr[i]*2)!=mp.end())
            {  
                if(arr[i]==0)
                {
                    if(z>=2)
                    {
                        return true;
                    }
                   
                }
                else {
                return true;
                }
            }

        }

        return false;

    }
};