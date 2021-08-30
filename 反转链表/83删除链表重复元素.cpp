#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
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
  ListNode* deleteDuplicates(ListNode* head) //I  删除重复元素1 我自己想的方法
  {
    ListNode *pHead = new ListNode(0);
    pHead->next=head;
    auto p = head;
    auto q = head->next;
    int tmp;
    int flag=0;
    while(q)
    {  
       tmp = p->val;
       while(q&&q->val==tmp )
       {
           p->next=q->next;
           q=q->next;
       }
       if(!q)
       break;
       p=q;
       q=q->next;
    }
    return  pHead->next;

    }


    ListNode *deleteDuplicates11(ListNode *head) //参考别人写法
    {
       auto pre = head;
       auto cur = pre->next;
       while(cur)
       {
           if(pre->val!=cur->val)
           {
               pre->next=cur;
               pre=pre->next;
           }
           cur=cur->next;
       }
       pre->next=NULL;
       return head;
    }

      ListNode* deleteDuplicates2(ListNode* head) //II
      {
        //   auto pHead= new ListNode(101);
        //   pHead->next =head;
        //   auto p = pHead;
        //   auto q = p->next;
        //   while(q)
        //   {
        //       int val = p->val;
        //       int  cnt = 0;
        //       while(q&&q->val==val)
        //       {
        //              cnt++
                     
        //       }
        //       if(!q)
        //       break;
        //       p =q;
        //       q=q->next;
        //   }
        map<int,int> mymap;
        auto p = head;
    while(p)
    {
        mymap[p->val]++;
        p=p->next;
    }
    for(map<int,int>::iterator it = mymap.begin();it!=mymap.end();)
    {
        if (it->second >1)
        mymap.erase(it++);
        else
        it++;
    }

    auto pHead=new ListNode(0);
    pHead->next =head;
     p = pHead;
    map<int,int >::iterator it;
    int flag = 0;
    while(head)
    {
        flag = 0;
      it = mymap.find(head->val);
      if(it==mymap.end())
      {
          flag = 1;
          p->next=head->next;
          head=head->next;
      }
       
       if(!flag)
       {
           p=p->next;
       head=head->next;
       }
    }
    return  pHead->next;

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





int main(int argc,char **argv)
{
    vector<int>  array{1,1,2,2};
    auto head= initNode(array);
    showNode(head);
    head=deleteDuplicates11(head);
     showNode(head);
}