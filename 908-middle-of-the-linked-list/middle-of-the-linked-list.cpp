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
        
        int l = 0;

        ListNode* temp = head;

        while(temp)
        {
            l++;
            temp = temp->next;
        }

         int mid = l/2;

         mid = mid+1;

         int c=0;

         while(head)
         {  
            c++;
           if(c==mid)
           {
            return head;
           }
           head = head->next;
           
         }

         return  temp;





    }
};