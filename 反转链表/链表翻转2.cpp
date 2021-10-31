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

  ListNode *reverseNode (ListNode * head,int left ,int right)
  {
      ListNode *pHead = new ListNode(-1);
      pHead->next=head;
      auto first = pHead;
      for(int i = 0; i<left-1;i++)
       first=first->next;             //第一段的尾巴
      
      auto second  = first->next;    //第二段的头部
      auto pre = second;
      auto cur = pre->next;
      for(int i =left; i<right;i++)
      {
          auto tmp = cur->next;
          cur->next =pre;
          pre=cur;
          cur = tmp;
      }
      first->next =pre;      //pre现在指向了right，所以第一段的最后一部分first指向right
      second->next  = cur;   
      return pHead->next;    
  }

ListNode *rotateList(ListNode * head,int k)
{
    if(!head||!head->next||k<1) return head; 
    ListNode * pHead = new ListNode(-1);
    pHead->next = head;
    auto p = head;
    auto last =pHead;
    int len = 0;          //1.计算出链表的长度
    while(p)
    {
        len++;
        p = p->next;
        last=last->next;         //1.首先找出最后一个点，用来连接头结点，
    }
    // last = p;
     k = (k)%len;             //如果k大于链表的长度，那么就取余数
     if(!k)
     return head;

    p = head;
    auto pre =pHead;
    for(int i = 0; i<k ;i++)      //pre，p 找出要旋转的第一个节点的前一个节点pre
    p = p->next;
    while(p)
    {
        p = p->next;
        pre=pre->next;
    }
    pHead->next =pre->next;  //将phead指向pre的下一个节点
    last->next =head;        //最后一个节点指向head
    pre->next = NULL;        //pre的最后一个节点置空
     return pHead->next;

}


ListNode *rotateList1(ListNode * head,int k)
{
    if(!head||!head->next||k<1) return head; 
    auto p = head;
    ListNode* last =NULL;
    int len = 0;          //1.计算出链表的长度
    while(p)
    {
        len++;
        p = p->next;
        if(p)
        last= p;             //找出最后一个不是空的节点，让他连接旧的头结点
    }
    k = k%len;
    if(!k)
    return head;         //如果k=0,那么直接返回
    p=head;
    for(int i = 0; i<len-k-1;i++)
    p = p->next;                          //找到要旋转的前一点
   auto newHead=p->next;
   last->next =head;
   p->next =NULL;
 
    
    return newHead;
}
int main(int argc,char **argv)
{
    vector<int>  array{1,2,3};
    auto head= initNode(array);
    showNode(head);
     head = rotateList1(head,3);

     showNode(head);
}
  
  
  
  
  
  
  
  
  