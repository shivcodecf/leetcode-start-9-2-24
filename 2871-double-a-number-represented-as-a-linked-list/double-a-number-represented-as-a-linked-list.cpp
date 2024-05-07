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

 #include<bits/stdc++.h>

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

      if(head==NULL)
      {
        return head;
      }

      ListNode *cur= head, *prev=nullptr;

      while(cur!=NULL)
      { 

         int newVal = cur->val*2;
         
         if(newVal<10)
         {
            cur->val=newVal;
         }
         else {
            
            cur->val =newVal%10;
            if(prev==nullptr)
            {
                ListNode* newNode = new ListNode(1);
                head=newNode;
                head->next= cur;
            }
            else {
                prev->val+=1;
            }
          
         }
           prev = cur;
            cur = cur->next;


      }
      return head;




    }
};