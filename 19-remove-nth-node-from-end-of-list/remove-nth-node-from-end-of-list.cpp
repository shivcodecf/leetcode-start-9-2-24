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

       int cnt=0;

       if(head==NULL)
       {
        return head;
       }

       while(temp!=nullptr)
       {
          cnt++;

          temp = temp->next;
       } 

       int flag = cnt-n;
       temp=head;

       if(flag==0)
       {

        head = head->next;
        return head;

       }
     

       else{

          ListNode *prev;

          int cnt1=0;
           
         for(int i=0;i<flag;i++)
         {

          
            

            prev = temp;
            temp = temp->next;

         }

         prev->next = temp->next;

         delete temp;

         return head;

        


       }

        return head;




    }
};