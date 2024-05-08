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
    bool isPalindrome(ListNode* head) {

     ListNode* temp= head;

     string s1="";
     int len=0;
     vector<int>v,v1;

     while(temp!=nullptr)
     {
        v.push_back(temp->val);
        temp=temp->next;
        len++;
     } 

        ListNode* node = nullptr;

        while (head != nullptr) {
              ListNode* temp = head->next;
            
           
             head->next = node;
           
            
             node = head;
             head = temp;

        }

        ListNode*temp1= node;

        while(temp1!=nullptr)
        {
            v1.push_back(temp1->val);
            temp1 = temp1->next;
        }
         
         for(int i=0;i<len;i++)
         {
            if(v[i]!=v1[i])
            {
                return false;
            }
         }

         return true;
        





    }
};