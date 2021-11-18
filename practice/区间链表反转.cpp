#include <iostream>
#include <vector>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode (int val):val(val),next(NULL){}
};
void show(ListNode *head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
ListNode *InitNode(vector<int>nums)
{
    ListNode *pHead = new ListNode(-1);
    ListNode *pTail =pHead;
    for(int i = 0; i<nums.size(); i++)
    {
        ListNode *pNew = new ListNode(nums[i]);
        pTail->next = pNew;
        pTail=pNew;
    }
    auto tmp = pHead->next;
    delete pHead;
    return  tmp;  
}
ListNode * reverseQujian(ListNode *begin,ListNode *end)
{
    ListNode *p=NULL;
    ListNode *q = begin;
    while(q!=end)
    {
        ListNode *tmp = q->next;
        q->next=p;
        p=q;
        q=tmp;
        
    }
    return p;
}

ListNode *invlReversal(ListNode *head,int s,int end)
{
     ListNode *pHead = new ListNode(-1);
     pHead->next = head;
     ListNode *tmp = pHead;
     for(int i = 0; i<s-1; i++)
     tmp=tmp->next;                   //first
     
     auto first = tmp;
     ListNode *second = first->next;

     for(int i = 0; i<end-s+1; i++)
     tmp = tmp->next;
     auto third = tmp;
     auto forth = third->next;

     reverseQujian(second,forth);

     first->next =third;

     second->next  =forth;

     return pHead->next;
     
}
    
int main(void)
{
    vector<int >nums{1,2,3,4,5};
    auto head = InitNode(nums);
    show(head);
    auto newHead=invlReversal(head,1,2);
    show(newHead);
    return 0;
}