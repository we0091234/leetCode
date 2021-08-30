#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr){}
};
void show(ListNode *head)
{
    while(head)
    {
        if (head->next)
            cout<<head->val<<"->";
        else
            cout<<head->val<<endl;
        
        head=head->next;
    }
}

void initListNode(ListNode * &head,vector<int> &array)
{
   ListNode * pHead=new ListNode(0);
   auto pTail=pHead;
   for(auto &val:array)
   {
       pTail->next=new ListNode(val);
       pTail=pTail->next;
   }
   head = pHead->next;
   delete pHead;
}
ListNode * ListNodeReverse(ListNode *&head,int left,int right)
{

    auto pHead = new ListNode(0);
    pHead->next =head;
    auto first = pHead;
    for(int i = 1; i<left;i++)
    {
        first = first->next;
    }
   auto second = first->next;
   auto pre=second;
   auto cur =second->next;
   for(int i = left;i<right;i++)
   {
       auto tmp = cur->next;
       cur->next =pre;
       pre=cur;
       cur=tmp;
   }

   first->next =pre;
   second->next =cur;
   return pHead->next;
}


ListNode *ListMergeTwo(ListNode *l1, ListNode* l2)
{
    auto l3 = new ListNode(0);
    auto pTail = l3;
    while(l1&&l2)
    {
        if(l1->val<l2->val)
        {
            pTail->next =new ListNode(l1->val);
            pTail=pTail->next;
            l1=l1->next;
        }
        else
        {
            pTail->next=new ListNode(l2->val);
            pTail=pTail->next;
            l2=l2->next;
        }
    }
    if(l1)
    {
        pTail->next =l1;
    }
    if(l2)
    {
         pTail->next =l2;
    }
    return l3->next;
}

ListNode * ListNodeMerge(vector<ListNode*> lists) //分治法
{
    // ListNode *l3 = nullptr;
    // for (int i = 0; i<lists.size(); i++)
    // {
    //     l3=ListMergeTwo(l3,lists[i]);
    // }
    // return l3;
    if(lists.size()==0)
    return nullptr;
    if(lists.size()==1)
    return lists[0];
    if(lists.size()==2)
    return ListMergeTwo(lists[0],lists[1]);
    vector<ListNode *>l,r;
    int mid = lists.size()/2;
    for(int i = 0; i<mid; i++)
    {
        l.push_back(lists[i]);
    }
     for(int i = mid; i<lists.size(); i++)
    {
        r.push_back(lists[i]);
    }
    return ListMergeTwo(ListNodeMerge(l),ListNodeMerge(r));
}

ListNode *rotateListNode(ListNode *head ,int k)
{

     ListNode *pHead = new ListNode(0);
     pHead->next =head;
     
     auto p =head;
     int length=0;
     while(p)
     {
         length++;
         p=p->next;
     }
      if (length==0||k==0)
     {
         return head;
     }
     p=head;
     int i;
     k =k%length;
     for( i=1; i<length-k; i++)
     {
         p=p->next;
     }
    
     
     auto second = p->next;
     if (second)
     {
     auto last= second;
     auto final =last->next;
     while(final)
     {
       last=last->next;
       final=final->next;
     }
     p->next =NULL;
     pHead->next =second;
     last->next =head;
     }
    
     return pHead->next;
     
}

int main(int argc, char **argv)
{
    vector<int> array1={1,2,3,4,5};
    vector<int> array2={2};
    vector<int> array3={26};
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    ListNode *head3 = nullptr;
    initListNode(head1,array1);
     initListNode(head2,array2);
      initListNode(head3,array3);
      vector<ListNode *> lists={head1,head2,head3};
    show(head1);
    // show(head2);
    // show(head3);
    // auto l3 =ListMergeTwo(head1,head3);
     auto l3 =rotateListNode(head3,1);
//    head= ListNodeReverse(head,1,1);
    show(l3);
    return 0;
}