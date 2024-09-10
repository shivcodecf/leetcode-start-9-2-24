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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
      

        ListNode* temp = head;

        ListNode* prev = temp;

         temp = temp->next;

         vector<int>v;

         v.push_back(prev->val);


       while(temp!=nullptr)
       {  

          int x= prev->val;

          int y= temp->val;

          int z = __gcd(x,y);

         
          v.push_back(z);

          v.push_back(y);

          prev = temp;

          temp = temp->next;



       }


    ListNode* newhead = new ListNode(v[0]);
    ListNode* current = newhead;

    // Iterate through the vector and create the linked list
    for (size_t i = 1; i < v.size(); ++i) {
        current->next = new ListNode(v[i]);
        current = current->next;
    }

    return newhead;

          


       





    }
};