#include <iostream> 
#include <cstdlib>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



void initLinkList(ListNode *&l1,vector<int>&array) 
{
    l1 = (ListNode*)malloc(sizeof(ListNode));
    l1 ->val=array[0];
    l1->next=NULL;
    ListNode *pTail = l1;
    for(int i = 1; i<array.size(); i++)
    {
        ListNode *pNew = (ListNode*)malloc(sizeof(ListNode));
        pNew ->val=array[i];
        pNew->next=NULL;
        pTail->next = pNew;
        pTail=pNew;
    }

}

void show(ListNode* l1)
{
    while (l1) 
    {
        cout<<l1->val<<" ";
        l1=l1->next;
    }
    cout<<endl;
}

int getLength(ListNode* head)
{
    int length=0;
    auto p=head;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}

ListNode *mergeListNode(ListNode*l1,ListNode* l2)
{
    ListNode *l3 = new ListNode(0);
    ListNode *pTmp = l3;
    while(l1&&l2)
    {
       if(l1->val<l2->val)
       {
           pTmp->next = new ListNode(l1->val);
           pTmp=pTmp->next;
           l1=l1->next;
       }
       else 
       {
            pTmp->next = new ListNode(l2->val);
           pTmp=pTmp->next;
           l2=l2->next;
       }
    }

    if (l1)
    {
        pTmp->next = l1;
    }
    if(l2)
    {
        pTmp->next =l2;
    }
    return l3->next;
}

 ListNode* swapPairs(ListNode* head) 
 {
     ListNode* l3= new ListNode(0);
     auto pTail3=l3;
     auto p=head;
     auto q=head->next;
     while(p&&q)
     {
         pTail3->next=new ListNode(q->val);
         pTail3=pTail3->next;
         pTail3->next=new ListNode(p->val);
         pTail3=pTail3->next;
         p=q->next;
         if(!p)
         break;
         q=p->next;
     }
    if(p)
    {
         pTail3->next=new ListNode(p->val);
         pTail3=pTail3->next;
    }

       return l3->next;
    }

int main(int argc, char** argv)
{
    vector<int > array1={1,2,3,4};
    vector<int> array2={9,9,9,9};
    ListNode *l1 =NULL;
    ListNode *l2 =NULL;
    initLinkList(l1,array1);
     initLinkList(l2,array2);
    show(l1);
    cout<<getLength(l1)<<endl;
    // l1=linkListReverse(l1);
   auto l3=swapPairs(l1);
     show(l3);
    return 0;
}