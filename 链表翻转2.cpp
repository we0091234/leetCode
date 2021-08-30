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

int main(int argc,char **argv)
{
    vector<int>  array{1,2,3,4,5,6,7};
    auto head= initNode(array);
    showNode(head);
     head = reverseNode(head,1,7);

     showNode(head);
}
  
  
  
  
  
  
  
  
  