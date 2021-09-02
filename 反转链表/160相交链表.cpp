#include <iostream>
#include <vector>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(NULL){}
};

void showNode (ListNode *head)
{
    if(head)
    {
    cout<<head->val<<" ";
    showNode(head->next);
    }

};

ListNode *initNode(vector<int>&array)
{
   ListNode *pHead = new ListNode(-1);
   ListNode *pTail =pHead;
   int len = array.size();
   for(int i = 0; i<len; i++)
   {
       pTail ->next = new ListNode (array[i]);
       pTail = pTail->next;
   }
   return pHead->next;
}

ListNode *intiXiaojiao(ListNode *head1,ListNode *head2)
{
    auto p=head1;
    while(p->next)
    p = p->next;
    p->next=head2;
    return head1;
}

ListNode * intersect(ListNode *head1,ListNode *head2)
{
    ListNode *p = head1;
    ListNode *q = head2;
    while(p!=q)
    {
          if(!p) p=head2;
          else p=p->next;
          if(!q) q=head1;
          else q = q->next;
    }
    return p;
}



int main (int argc, char **argv)
{
    vector<int > array{1,2,3,4,5};
    vector<int >array1{6,7,8,4,5};
    vector<int> array3{99,100};
    ListNode *head=initNode(array);
    ListNode *head2=initNode(array1);
    ListNode *head3=initNode(array3);
    
    head=intiXiaojiao(head,head3);
    head2=intiXiaojiao(head2,head3);
    auto inster = intersect(head,head3);
    showNode(inster);
    return 0;
}