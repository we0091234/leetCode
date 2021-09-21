#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(NULL){}
};

struct cmp
{
    bool operator()( ListNode *&a, ListNode *&b)       //构造优先队列的比较方式
    {
        return a->val > b->val;
    }
};

void showNode(ListNode *head)
{
    if(head)
    {
        cout<<head->val<<" ";
        showNode(head->next);
    }
}
ListNode *initFromArray(vector<int>nums)
{
    int len =nums.size();
    ListNode *pHead = new ListNode(-1);
    ListNode *pTail =pHead;
    for(int i = 0; i<len; i++)
    {
         ListNode *pNew = new ListNode(nums[i]);
         pTail->next= pNew;
         pTail = pNew;
    }
    return pHead->next;
}

ListNode *MergeKListNode(vector<ListNode *>lists)
{
    ListNode *pHead =new ListNode(-1);
    ListNode *pTail = pHead;
    priority_queue<ListNode * ,vector<ListNode *> ,cmp > myqueue;
    for(int i = 0; i<lists.size(); i++)
    {
        if(lists[i])          
        myqueue.push(lists[i]);  //加入到优先队列
    }
    
    while(!myqueue.empty())
    {
        auto tmp = myqueue.top();
        pTail->next=tmp;
        pTail=tmp;
        myqueue.pop();
        
        // if(tmp)
        tmp = tmp->next;
        if(tmp)
        myqueue.push(tmp);
        
    }
    return pHead->next;
    // while(!myqueue.empty())
    // {
    //     auto tmp = myqueue.top();
    //     cout<<tmp->val<<endl;
    //     myqueue.pop();
    // }
}

int main(void)
{
    vector<int> nums1{1};
    vector<int>nums2{2};
    vector<int>nums3{3};
    ListNode *l1 = initFromArray(nums1);
    ListNode *l2 = initFromArray(nums2);
    ListNode *l3 = initFromArray(nums3);
    showNode(l3);
    vector<ListNode *> lists{l1,l2,l3};
    auto l4 = MergeKListNode(lists);
    showNode(l4);
   

    return 0;
}