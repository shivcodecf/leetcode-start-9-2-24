/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
    map<int, int> mp;

    // Count the occurrences of each number in the nums vector
    for(int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    vector<int> v;

    // Traverse the linked list
    while(head != nullptr) {
        int temp = head->val;

        // If the value is not in the nums vector, add it to the new vector
        if(mp.find(temp) == mp.end()) {
            v.push_back(temp);
        }

        head = head->next;
    }

    // If the vector is empty, return nullptr
    if(v.empty()) {
        return nullptr;
    }

    // Create the new linked list from the vector
    ListNode* newHead = new ListNode(v[0]);
    ListNode* current = newHead;

    for(int i = 1; i < v.size(); ++i) {
        current->next = new ListNode(v[i]);
        current = current->next;
    }

    return newHead;
}
};