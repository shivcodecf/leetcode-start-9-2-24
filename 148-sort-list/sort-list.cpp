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
    ListNode* sortList(ListNode* head) {

        if(head==NULL)
        {
            return NULL;
        }
       
       ListNode*temp=head;

       vector<int>v;
       int len=0;

       while(temp!=nullptr)
       {
        v.push_back(temp->val);

        temp=temp->next;
        len++;
       }

       sort(v.begin(),v.end());

       ListNode*temp1=nullptr,*temp2=nullptr;
       int i=0;

       temp1= new ListNode(v[i]);

       head = temp1;

       

       for(int i=1;i<len;i++)
       {
            temp2 = new ListNode(v[i]);

            temp1->next = temp2;

            temp1=temp2;

       }

      

       return head;








    }
};