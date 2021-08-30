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

   ListNode* oddEvenList(ListNode* head) 
   {
      
       if(head == NULL || head->next == NULL)
       return head;
       
       auto even = head;  //定义双链表，even 奇链表，和odd偶链表的头，最后将奇链表的尾巴，指向偶链表的头即可
       auto odd = head->next;
       auto evenTail =even;
       auto oddTail = odd;
       auto p = oddTail->next;
       int val = 3;
       while(p)
       {
           if (val%2)
           {
           evenTail->next =p;
           evenTail = p;
           }
           else
           {
            oddTail->next =p;
            oddTail = p;
           }

            val+=1;
            
           p = p->next;
          
       }

      oddTail->next =NULL;
       evenTail->next=odd;

       return  even;
      

    }

int main(int argc,char **argv)
{
    vector<int>  array{2,1,3,5,6,4,7};
    auto head= initNode(array);
    // showNode(head);
     head = oddEvenList(head);

     showNode(head);
}
  
  
  
  
  
  
  
  
  