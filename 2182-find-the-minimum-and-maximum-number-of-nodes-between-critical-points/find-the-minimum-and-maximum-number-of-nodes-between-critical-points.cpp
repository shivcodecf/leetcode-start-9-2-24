class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>store;

        int ans1 = INT_MAX, cur, next, n;
        int last = head->val, position = 2;

        while(head->next)
        {
            cur = head->val, next = head->next->val;

            if((last > cur and cur < next) || (last < cur and cur > next)) 
                store.push_back(position);
            position++;
            last = cur, head = head->next;

            n = store.size();
            if(n > 1) ans1 = min(ans1, store[n-1] - store[n-2]);
        }
        
        if(ans1 == INT_MAX) return {-1, -1};
        
        return {ans1, store.back() - store[0]};
    }
};