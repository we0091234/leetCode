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

ListNode* linkListReverse(ListNode* &l1)  //链表反转
{
   ListNode* p = NULL;
   ListNode* q = l1;
   while(q)
   {
       auto t = q->next;
       q->next=p;
       p =q;
       q=t;
   }
   return p;
}

ListNode * linkListReverse1(ListNode* &l1,int left ,int right)  //链表反转2 自己实现
{
  ListNode *pHead = new ListNode();
  pHead->next = l1;
  auto p = pHead;
  auto q = pHead->next;
  int i =0;
  ListNode *m =nullptr;
  ListNode *n=nullptr;
  ListNode *t=nullptr;
  while(q)
  {
      i+=1;
      if(i==left)
        m=p; 
      if (i==right)
      {
        n=q;
        t=n->next;
      }
      p=p->next;
      q=q->next;
  }
  p =m;
  q=p->next;
  while (q!=t)
  {
     auto r = q->next;
     q->next=p;
     p=q;
     q=r;
  }
  if (left!=1)
  {
  m->next->next=q;
  m->next=n;
  }
  else
  {
      pHead->next->next=t;
      pHead->next=n;
  }
  
  return pHead->next;
 

}

ListNode * linkListReverse2(ListNode* &l1,int left ,int right)//链表反转二 官方实现
{
    if(left==right)  //如果left==right 就返回原链表
    return l1;
    ListNode * pHead = new ListNode(0);  //给链表加一个头节点
    pHead->next=l1;
    ListNode *pre = pHead;
    for(int i = 0; i<left-1;i++) //这个循环是找到第一段链表的最后一个数  比如 1,2,3,4,5 left=3,right=4,那么pre就停留在2上面
    {
        pre=pre->next;            //1,2是一段 3，4是一段需要反转的，5是一段
    }
    auto first=pre;  //first代表的就是第一段的最后一个数2，
    auto second = first->next; //second表示第二段第一个数3
    pre=second;
    auto cur = pre->next;

    for(int i =left;i<right;i++)  //反转3,4这一段
    {
        auto next = cur->next;
        cur->next=pre;
        pre=cur;
        cur = next;
    }
    second->next=cur;  //反转完3,4之后，3要连接到5
    first->next=pre;    //要把之前的first链接到4
    return pHead->next;


}
int main(int argc, char** argv)
{
    vector<int > array1={1};
    vector<int> array2={9,9,9,9};
    ListNode *l1 =NULL;
    initLinkList(l1,array1);
    show(l1);
    // l1=linkListReverse(l1);
    l1=linkListReverse2(l1,1,1);
     show(l1);
    return 0;
}