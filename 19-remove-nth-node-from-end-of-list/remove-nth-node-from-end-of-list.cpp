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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;

        int c = 0;

        while (temp) {
            c++;
            temp = temp->next;
        }

        int start = c - n ;

        if(start==0)
        {
           head = head->next;
           return head;
        }

        int c1=0;

        ListNode* temp1 = head;

        while(temp1)
        {
           c1++;

          if(c1==start && c1+1!=c)
          {
            temp1->next = temp1->next->next;
          }
          else if(c1==start && c1+1 == c)
          {
            temp1->next = NULL;
          }

          temp1 = temp1->next;

        }

        return head;




    }
};