class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

       
        vector<pair<double,pair<int,int>>>v;
        
     for(int i=0;i<arr.size();i++)
     {
        for(int j=0;j<arr.size();j++)
        {
            double result = double(arr[i]) / arr[j];

            pair<int, int> second_pair = make_pair(arr[i], arr[j]);

   
            pair<double, pair<int, int>> value_to_push = make_pair(result, second_pair);
             v.push_back(value_to_push);

        }
     }

        sort(v.begin(),v.end());

        return {v[k-1].second.first,v[k-1].second.second};



    


    }
};