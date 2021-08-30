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

 ListNode *reverse(ListNode *head)
 {
     ListNode *pre =NULL;
     ListNode *cur = head;
     while(cur)
     {
         ListNode *next = cur->next;
         cur->next =pre;
         pre=cur;
         cur = next;
     }
     return pre;
     
 }

int getlength(ListNode *head)
{
    int length= 0;
    while(head)
    {
      length++;
      head=head->next;
    }
    return length;
}

 bool isPalindrome(ListNode* head) 
  {
     auto small = head,big=head;
     int i = 0;
     while(big &&big->next )                          //来一个双指针，big每次走两步，small每次走一步,big需要放在前面，因为如果big为NULL的话，就没有big->next
     {
         
         big = big ->next->next;
         small=small->next;
     }
     if(big)                              //如果big部位NULL，说明链表是奇数，small还要往后一步
     small=small->next;
     auto right = reverse(small);       //反转后面一段链表
     showNode(right);
     auto left = head;
     while(right)                    //后一段链表和前一段链表比对，一样的话就是回文
     {
         if(right->val!=left->val)
         return false;
         right=right->next;
         left=left->next;
     }
     return true;

}



int main(int argc,char **argv)
{
    vector<int>  array{1,2,2,1};
    auto head= initNode(array);
    // showNode(head);
    cout<<isPalindrome(head)<<endl;;
    //  showNode(head);
}