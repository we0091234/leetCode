
  #include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr){}
};

ListNode *initNode(vector<int> &array)
{
    ListNode *pHead = new ListNode(0);
    auto pTail = pHead;
    for(int i = 0; i<array.size(); i++)
    {
        pTail->next=new ListNode(array[i]);
        pTail=pTail->next;
    }
    return pHead->next;
}
void showNode(ListNode *head)
{
    while(head)
    {
        if(head->next)
            cout<<head->val<<"->";
        else
         cout<<head->val<<endl;
         head=head->next;
    }
}

 
  ListNode* removeElements(ListNode* head, int val) {
      ListNode *pHead = new ListNode(-1);
      pHead->next = head;
      auto p = pHead;
      auto q = p->next;
      while(q)
      {
          if(q->val==val)
          {
              p->next =q->next;
              q = p->next;
          }
          else
          {
            
              p=p->next;
              q=p->next;
          }
      }
      return pHead->next;

    }

int main(int argc,char **argv)
{
    vector<int>  array{1,2};
    auto head= initNode(array);
    showNode(head);
     auto l3 = removeElements(head,1);

     showNode(l3);
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
