  
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





  ListNode* sortList(ListNode* head) {          //选择排序
      
       auto pre = head;
       ListNode *p = NULL;
       ListNode *tmp = NULL;
       while (pre->next)
       {
           int min = pre->val;
           p = pre->next;
           tmp =NULL;
           while(p)
           {
               if(p->val<min)
               {
                 tmp =p;
                 min = p->val;
               }
               p = p->next;
           }
           if(tmp)
           {
             int tmpval = pre->val;
             pre->val = tmp->val;
             tmp->val = tmpval;
           }
            pre=pre->next;
       }
    
       return  head;
    }



ListNode *MergeNode(ListNode *head1,ListNode *head2)
{
    auto pHead = new ListNode(0);
    auto pTail = pHead;
    
    while(head1&&head2)
    {
        if(head1->val<head2->val)
        {
          pTail->next=head1;
          pTail = head1;
          head1=head1->next;
        }
        else
        {
          pTail->next=head2;
          pTail = head2;
          head2=head2->next;
        }
    }
    if(head1)
    pTail->next=head1;
    if(head2)
    pTail->next=head2;

    return pHead->next;
}
ListNode *guiBingSort(ListNode *head) //归并排序
{
   if(!head || !head->next)
   return head;
   ListNode *pHead = new ListNode(0);  //重要 不然如果从head开始的话，1，2,3,4 slow会指向3，这样就不能平均分配了
   pHead->next = head;
   auto  slow = pHead;
   auto fast = pHead;
   while(fast && fast->next)
    {
      slow=slow->next;
      fast=fast->next->next;
    }
    auto newHead = slow->next;
    slow->next=NULL;
    head=guiBingSort(head);
    cout<<"Head:";
    showNode(head);
    newHead=guiBingSort(newHead);
    cout<<"newHead:";
    showNode(newHead);
    // MergeNode(head,newHead);
    return MergeNode(head,newHead);
}

ListNode *insertSort(ListNode *head) //插入排序
{
    ListNode *pHead = new ListNode(0);
    pHead->next = head;
    auto pTail = head;
    auto cur = head->next;
    while (cur)
    {
        auto tmpPre=pHead;
        auto tmp = pHead->next;
        while(cur->val>tmp->val && tmpPre!=pTail)
        {
            tmpPre=tmpPre->next;
            tmp = tmp->next;
        }
        if(tmpPre==pTail)
        {
             tmpPre->next=cur;
             pTail = cur;
        }
      else
      {
        pTail->next=cur->next;
        tmpPre->next=cur;
        cur->next=tmp;
      }
      cur=pTail->next;
    }
    return pHead->next;
}
int main(int argc,char **argv)
{
    vector<int>  array{4};
    vector<int> array1{2};
    vector<int> array2{1,5,2};
    auto head= initNode(array);
     auto head1= initNode(array1);
      auto head2= initNode(array2);
    // showNode(head2);
    auto head3=MergeNode(head,head1);
    auto head4= insertSort(head2);
     showNode(head4);
}
  
