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



ListNode *reverseNode(ListNode *left,ListNode *right) //作用是将一段[2，4) 将节点left到right之间的链表反转，比如[1,2,3,4,5]如果left=1,right=3  反转就变为[2,1,3,4,5] right是闭区间
{
    if(left==NULL)
    return left;
    auto pre =left;
    auto cur=pre->next;
    while(cur!=right)
    {
        auto tmp =cur->next;
        cur->next =pre;
        pre=cur;
        cur=tmp;
    }
    // left->next =NULL;
    return pre;
}

ListNode *kGroupReverse(ListNode *head,int k)
{
    if (!head||k==0)
    {
          return head;
    }
    auto pHead =new ListNode(0);
    pHead->next=head;
    auto pTail =pHead;
    auto p =head;
    // auto newHead=head;
    while(p)
    {
        int i=0;
        for(i = 0; i<k&&p;i++)  //让p移动到下一段的第一个，比如[1,2,3,4,5] k=3的话，那么第一次p就移动到4
        {
            p=p->next;
        }
        // auto newHead= p;
        if(i==k)        //如果满足k个，那么久进行反转，否则不操作
        {
          auto newHead=reverseNode(head,p);   //返回的是一组新的头，比如上面1，2,3开始1是头，那么经过这个函数之后，3就是头了，变成3->2->1
           pTail->next =newHead;              //此时需要将pTail和3连接起来，变为pHead->3>2->1，第一次pTail就是pHead; 也就是上一段的尾巴需要指向新一段的头
           head->next =p;                     //此时的head需要指向下一段的head也就是p=4，就是将4和1连接起来  [3->2>->1]->4->5 
           pTail=head;                        //让pTail等于上一段的尾巴这里是1
           head=p;                           //然后head等于第二段的头就是p=4
        }     
    }
    return  pHead->next;
}



int main(int argc,char **argv)
{
    vector<int>  array{1,2,3,4,5,6,7,9,10};
    auto head= initNode(array);
    showNode(head);
    head=kGroupReverse(head,4);
     showNode(head);
}