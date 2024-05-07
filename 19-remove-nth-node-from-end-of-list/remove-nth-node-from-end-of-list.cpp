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

       if(flag==0)
       {

        head = head->next;
        return head;

       }

         temp=head;
     

       

          ListNode *prev = NULL;

          int cnt1=0;
           
         while(temp!=nullptr)
         {

            cnt1++;


            if(cnt1-1 == flag)
            {
                prev->next = temp->next;
                delete(temp);
                break;
            }


            prev = temp;
            temp = temp->next;


         }

        


       

         return head;




    }
};