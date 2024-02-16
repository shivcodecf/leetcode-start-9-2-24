class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        using ll = long long;
        using pll = pair<ll, ll>;
        int n = nums1.size();
        
        vector<pll> arr;
        
        for(int i=0; i<n; i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        
        // sort arr in decreasing order based on nums2 values

        sort(arr.begin(), arr.end(), greater<pll>());
        
        // min-heap
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        // sum of elements in the priority queue
        ll sum=0;
        
        // add the first k elements to the priority queue
        for(int i=0; i<k; i++) {
            sum += arr[i].second;
            pq.push(arr[i].second);
        }
        
        ll result = sum*arr[k-1].first;
        
        // now try each element if it is the element
        // with smallest nums2 value
        for(int i=k; i<n; i++) {

            // remove the smallest element
            


            sum -= pq.top();
            pq.pop();
            
            // add the current element

            sum += arr[i].second;
            pq.push(arr[i].second);
            
            // find the result when the current element has
            // the smallest nums2 value
            result = max(result, sum*arr[i].first);
        }
        
        return result;
    }
};