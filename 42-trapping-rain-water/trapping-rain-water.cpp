class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) 
            return 0; 
        
        int res = 0;
        stack<int> s;   
        for(int i=0; i<height.size(); i++) {
            while(!s.empty() && height[i] > height[s.top()]) {
                int rightIdx = s.top();
                s.pop();
                
                if(s.empty()) 
                    break;
                
                int leftIdx = s.top();
                int length = min(height[i], height[leftIdx]) - height[rightIdx];
                int breadth = i - leftIdx - 1;
                int area= length*breadth;
                if(area>0)
                res += length*breadth;
            }
            s.push(i);
        }
        return res;
    }
    };