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
 using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
     
     int len=0;

     if(head==NULL)
     {
        return NULL;
     }

     ListNode*temp=head;

     vector<int>v;

     while(temp!=NULL)
     {
        len++;
       v.push_back(temp->val);
        temp=temp->next;
     }

     int x=k%len;

     int y=len-x,c=0;

     vector<int>v2;

     for(int i=0;i<len;i++)
     {

     c++;

     if(c>y)
     {
      v2.push_back(v[i]);
     }


     }

     c=0;

     for(int i=0;i<len;i++)
     {
        c++;
        if(c<=y)
        {
            v2.push_back(v[i]);
        }
     }

    //  for(int i=0;i<v2.size();i++)
    //  {
    //     cout <<v2[i]<<" ";
    //  } 

     ListNode*temp1= new ListNode(v2[0]),*prev=temp1;



    head=temp1;

    for(int i=1;i<v2.size();i++)
    {
       ListNode*temp1= new ListNode(v2[i]);

       prev->next=temp1;

       prev=temp1;
    }


     return head;






       
        
    }
};