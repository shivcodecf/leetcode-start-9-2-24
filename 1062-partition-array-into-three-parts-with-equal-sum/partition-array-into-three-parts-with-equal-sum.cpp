class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
          int n = arr.size();
    if (n < 3) false;  // At least 3 elements are required to split into 3 parts

    // Step 1: Compute the prefix sum array
    vector<int> pref(n);
    
    pref[0] = arr[0];

    map<int,int>mp;
    
    for (int i = 1; i < n; i++) {
        
        pref[i] = pref[i - 1] + arr[i];
        mp[arr[i]]++;
        
    }

    int sum = pref[n-1],sum1=0,ans=0;
    

    int target = sum/3;
    if(sum%3) return false;

    

    for(int i=0;i<n;i++)
    {
        sum1+=arr[i];


        if(sum1==target)
        {
            ans++;
            sum1=0;
        }

    }

    return ans>=3;
    
    

    }
};