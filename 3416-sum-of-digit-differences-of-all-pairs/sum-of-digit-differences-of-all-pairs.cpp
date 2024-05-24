class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        
        int m=to_string(nums[0]).size();
        
        long long res=0;
        for(int i=1;i<=m;i++){
            map<int, int> mp;
            
            for(int j=0;j<nums.size();j++){
                mp[nums[j]%10]++;
                nums[j]=nums[j]/10;
                
            }
            long long temp=0;
            for(auto i1: mp){
                for(auto i2:mp){
                    if(i1.first==i2.first)
                        continue;
                    
                    // cout<<i1.first<<" "<<i2.first<<"\n";
                    temp+=i1.second*i2.second;
                    
                }
                
            }
            temp/=2;
            // cout<<"====\n";
            
            res+=temp;
        }
        
        return res;
        
    }
};