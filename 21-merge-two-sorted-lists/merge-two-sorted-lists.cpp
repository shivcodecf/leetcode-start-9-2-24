class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy; // create a dummy node
        ListNode* temp = &dummy; // temp points to dummy

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next; // move temp ahead
        }

        // if any nodes remain
        if (l1) temp->next = l1;
        if (l2) temp->next = l2;

        return dummy.next;
    }
};
