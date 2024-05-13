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
    ListNode* reverseKGroup(ListNode* head, int k) {
     

      vector<int>v;
     ListNode *temp = new ListNode(*head);

      int len=0;


      while(temp!=NULL)
      {
        v.push_back(temp->val);

        temp=temp->next;
        len++;
      }
      vector<int>v2;
      int j=0;
      vector<int>v1;
      int c=0;

      for(int i=j;i<len;i++)
      {   
           
           int c=0;

          while(c+1<=k && j<len)
         {
           
            
           v1.push_back(v[j]);
           j++;
            c++;
         
          
         }
         
          if(v1.size()==k){
             reverse(v1.begin(),v1.end());
          }
       

         for(int m=0;m<v1.size();m++)
         {
            v2.push_back(v1[m]);
         }
         v1.clear();



      }  

       reverse(v1.begin(),v1.end());

     

    // //   for(int i=0;i<v1.size();i++)
    // //   {
    // //     v2.push_back(v1[i]);
    // //   }

    //   for(int i=0;i<v2.size();i++)
    //   {
    //     cout <<v2[i]<<" ";
    //   }

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