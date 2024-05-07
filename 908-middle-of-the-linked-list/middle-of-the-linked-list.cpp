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
    ListNode* middleNode(ListNode* head) {
       
       ListNode* temp= head;
       int len=0;

       while(temp!=NULL)
       {
        len++;
        temp=temp->next;
       }
       int mid=0;
       temp=head;

       if(len%2)
       {

        mid=len/2;
        mid=mid+1;

       }
       else {
        mid=len/2;
        mid=mid+1;
       }


       ListNode *prev;
       int cnt=0;

        for(int i=0;i<mid-1;i++)
       {
        //   cnt++;

        //   if(cnt==mid)
        //   {

        //     prev->next=temp->next;
        //     delete(temp);
        //     break;

        //   }
        //   prev=temp;

          head=head->next;

       }

       return head;




       
    }
};