#include <iostream>
#include <vector>
#include <set>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(NULL){}
};

void showNode (ListNode *head)
{
    if(head)
    {
    cout<<head->val<<" ";
    showNode(head->next);
    }

};

ListNode *initNode(vector<int>&array)
{
   ListNode *pHead = new ListNode(-1);
   ListNode *pTail =pHead;
   int len = array.size();
   for(int i = 0; i<len; i++)
   {
       pTail ->next = new ListNode (array[i]);
       pTail = pTail->next;
   }
   return pHead->next;
}

ListNode *initCircle(ListNode *head1)
{
    auto p=head1;
    while(p->next)
    p = p->next;
    p->next= head1->next;
    return head1;
}

ListNode * iscircle(ListNode *head) ////返回有环的节点
{
    auto p = head;
    set<ListNode *>mySet;
    while(head)
    {
        if(mySet.find(head)!=mySet.end())
        return  head;
        mySet.insert(head);
        head=head->next;
    }
    return NULL;
}

bool iscircle1(ListNode *head) ////使用set
{
    set<ListNode *>mySet;
    while(head)
    {
        if(mySet.find(head)!=mySet.end())
        return  true;
        mySet.insert(head);
        head=head->next;
    }
    return false;
}
bool iscircle11(ListNode *head) ////使用快慢指针，slow，fast ，fast和slow相交那么肯定有环
{
   auto slow = head;
   auto fast = head;
   while(fast && fast->next)
   {
       slow =slow->next;
       fast=fast->next->next;
       if(slow==fast)
       return true;
   }
   return false;
}




int main (int argc, char **argv)
{
    vector<int > array{1,2,3,4,5};
    vector<int >array1{6,7,8,4,5};
    vector<int> array3{99,100};
    ListNode *head=initNode(array);
    ListNode *head2=initNode(array1);
    ListNode *head3=initNode(array3);
    
    // head=initCircle(head);
     
     auto boolValue = iscircle11(head);
  
    if(boolValue)
    cout<<"有环"<<endl;
    else
    cout<<"无环"<<endl;
    return 0;
}