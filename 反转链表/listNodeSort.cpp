#include <iostream>
#include <vector>
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

ListNode *merGeTow(ListNode *l1,ListNode *l2)
{
    ListNode *head= NULL;
    if(l1->val<l2->val)
    {
        head=l1;
        l1=l1->next;
    }   
     else
    {
        head=l2;
        l2=l2->next;
    }    
    auto pTail =head;
    while(l1&&l2)
    {
        if(l1->val<l2->val)
        {
            pTail->next=l1;
            pTail=pTail->next;
            l1=l1->next;
        }
        else
        {
             pTail->next=l2;
            pTail=pTail->next;
            l2=l2->next;
        }
        
    }
    if(l1)
    pTail->next=l1;
    if(l2)
    pTail->next=l2;
    return head;
}

ListNode *mergeSort(ListNode *head)
{
    if(!head||!head->next) return head;
    ListNode *pHead = new ListNode(-1);  //要一个辅助的头结点，这样才能保证slow落在前面的中点上，比如，1,2,3,4如果不从pHead开始遍历，那么
    pHead->next = head;
    ListNode *slow = pHead;
    ListNode *fast = pHead;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = slow->next;
    slow->next =NULL;
   
    newHead=mergeSort(newHead);
    head = mergeSort(head);

    return merGeTow(head,newHead);
    
}

int main (int argc, char **argv)
{
    vector<int > array{1,2,3,4,5};
    vector<int >array1{6,7,8,9,10};
    vector<int> newArray{9,6,3,2,5,8,7,4,1,0};
    ListNode *head=initNode(array);
    ListNode *head2=initNode(array1);
    ListNode *newHead = initNode(newArray);
    ListNode *head3 = mergeSort(newHead);
    showNode(head3);
    return 0;
}