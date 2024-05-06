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
ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=NULL,*temp=head;
        while(temp!=NULL)
        {
            head=temp->next;
            temp->next=prev;
            prev=temp;
            temp=head;
        }
        return prev;
    }


    ListNode* removeNodes(ListNode* head) {

        if(head==nullptr)
        {
            return head;
        }


      ListNode* newHead=reverseList(head);

      int max=newHead->val;

      ListNode *p = newHead, *q=newHead->next, *r;

      while(q!=NULL)
      {
        r=q->next;
        if(max>q->val)
        {
          p->next=r;
          q=r;
        }
        else {
            max=q->val;
            p=q;
            q=r;
        }

      }
      newHead=reverseList(newHead);

      return newHead;










    }
};