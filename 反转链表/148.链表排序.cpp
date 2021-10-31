  
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


ListNode *quickSort(ListNode *head)
{
    
}
int main(int argc,char **argv)
{
    vector<int>  array{3,2,1};
    auto head= initNode(array);
    showNode(head);
    head=sortList(head);
     showNode(head);
}
  
