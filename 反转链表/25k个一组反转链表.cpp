#include <iostream>
#include <vector>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr){}
};

ListNode * initNode(vector<int> &arry)
{
    ListNode * pHead = new ListNode(0);
    ListNode *pTail = pHead;
    for(int i = 0; i<arry.size();i++)
    {
            pTail->next=new ListNode(arry[i]);
            pTail=pTail->next;
    }
    return  pHead->next;
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

ListNode * reverse(ListNode *head,ListNode *nextHead) //如果整条翻转就把nextHead变为NULL即可
{
    auto pre =head;
    auto cur = head->next;
    while(cur!=nextHead)
    {
        auto next = cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;  
    }
    // head->next=NULL;
    return pre;
}

ListNode * KgroupReverse(ListNode *head,int k) //普通版本
{
    if(!head || k==1)
      return head;
    ListNode *pHead = new ListNode(0);
    pHead->next = head;
    auto pTail = pHead;
    auto p=head;
    while(p)
    {
        int i;
        for( i = 0; i<k&&p; i++)
         p= p->next;
       if(i==k)
       {
       auto preHead = reverse(head,p);
       pTail ->next=preHead;
       pTail = head;
       head->next=p;
       head = p;
       }
    }
    return pHead->next;
}

ListNode * KgroupReverseRecursion(ListNode *head,int k) //递归版本
{
    if(!head || k==1)
      return head;
    auto cur = head;
    for(int i = 0; i<k;i++)
    {
        if(!cur)
        return head;
        cur=cur->next;
    }
    auto newHead = reverse(head,cur);
    head->next=KgroupReverseRecursion(cur,k);
    return newHead;

}



int main(void)
{
    vector<int> myArray{1,2,3,4,5};
    auto head = initNode(myArray);
    showNode(head);
    head=KgroupReverseRecursion(head,2);
    showNode(head);
    return 0;
}