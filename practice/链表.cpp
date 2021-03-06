#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
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

// ListNode *kGroupReverse(ListNode *head,int k)
// {
//     if (!head||k==0)
//     {
//           return head;
//     }
//     auto pHead =new ListNode(0);
//     pHead->next=head;
//     auto pTail =pHead;
//     auto p =head;
//     // auto newHead=head;
//     while(p)
//     {
//         int i=0;
//         for(i = 0; i<k&&p;i++)  //让p移动到下一段的第一个，比如[1,2,3,4,5] k=3的话，那么第一次p就移动到4
//         {
//             p=p->next;
//         }
//         // auto newHead= p;
//         if(i==k)        //如果满足k个，那么久进行反转，否则不操作
//         {
//           auto newHead=reverseNode(head,p);   //返回的是一组新的头，比如上面1，2,3开始1是头，那么经过这个函数之后，3就是头了，变成3->2->1
//            pTail->next =newHead;              //此时需要将pTail和3连接起来，变为pHead->3>2->1，第一次pTail就是pHead; 也就是上一段的尾巴需要指向新一段的头
//            head->next =p;                     //此时的head需要指向下一段的head也就是p=4，就是将4和1连接起来  [3->2>->1]->4->5 
//            pTail=head;                        //让pTail等于上一段的尾巴这里是1
//            head=p;                           //然后head等于第二段的头就是p=4
//         }     
//     }
//     return  pHead->next;
// }

// ListNode *KgroupVerseRecursion(ListNode *head,int k) //递归用法
// {
//     auto cur = head;
//    for(int i = 0; i<k; i++)
//    {
//        if(!cur) return head;
//         cur = cur->next;
//    }

//    auto newHead = reverseNode(head,cur);
//   auto p = KgroupVerseRecursion(cur,k);
//   head->next = p;
//   return  newHead;
// }

ListNode *reserveList(ListNode *begin,ListNode *end)
{
   ListNode * pre =NULL;
   ListNode *cur = begin;
   while(cur!=end)
   {
       auto tmp =cur->next;
       cur->next = pre;
       pre=cur;
       cur= tmp;
   } 
   return pre;
}
ListNode *kGroupReverse(ListNode *head,int k)
{
    ListNode *tmp = head;
    for(int i = 0; i<k; i++)
    {
        if(!tmp)
        return head;
        tmp=tmp->next;
    }
    auto newHead =reserveList(head,tmp);
    auto nextHead=kGroupReverse(tmp,k);
    head->next = nextHead;
    return newHead;
}

ListNode *reserveRng(ListNode *head,int left ,int right) //区间反转链表
{
    ListNode *pHead = new ListNode (-1);
    pHead ->next = head;
    ListNode *first = pHead;
    for(int i = 0; i<left-1;i++)
     first = first->next;
    auto second = first->next;
    ListNode *pre = NULL;
    ListNode *cur =second;
    for(int i=left-1; i<right;i++)
    {
      ListNode *tmp= cur->next;
      cur->next =pre;
      pre=cur;
      cur = tmp;
    }
    second->next  =cur;
    first->next =pre;
    return pHead->next;
}

bool isHuiwen(ListNode *head)  //回文链表
{
    auto *pHead = new ListNode (-1);
    pHead->next = head;
    auto slow = pHead;
    auto fast = pHead;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    slow = slow->next;
    auto right = reserveList(slow,NULL);
    // showNode(right);
    auto left = head;
    while(right)
    {
        if(right->val != left->val)
        return false;
        right = right->next;
        left=left->next;
    }
    return true;
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



ListNode *mergeTwo(ListNode *head1,ListNode *head2)
{
    ListNode *pHead= new ListNode (-1);
    ListNode *pTmp = pHead;
    while(head1&&head2)
    {
        if(head1->val<head2->val)
        {
            pTmp->next =head1;
            pTmp=head1;
            head1=head1->next;
        }
        else
        {
            pTmp->next =head2;
             pTmp=head2;
            head2=head2->next;
        }
    }
    if(head1)
    pTmp->next =head1;
    else
    pTmp ->next =head2;
    return pHead->next;
}
ListNode *mergeKList(vector<ListNode *> listArray) //采用递归的方法
{
    if(listArray.size()<=1) return listArray[0];
    vector<ListNode *>left;
    vector<ListNode *>right;
    int mid = listArray.size()/2;
    for(int i = 0; i<mid; i++)
    left.push_back(listArray[i]);
    for(int i = mid; i<listArray.size(); i++)
    right.push_back(listArray[i]);

    ListNode *newHead1= mergeKList(left);
    ListNode *newHead2= mergeKList(right);
    
   return mergeTwo(newHead1,newHead2);
}


struct cmp
{
    bool operator()(ListNode *a,ListNode *b)
    {
        return a->val>b->val;
    }

};

ListNode *mergeKlistQueue(vector<ListNode *>listArray)
{
    ListNode *pHead = new ListNode(-1);
    ListNode *pTail = pHead;
    priority_queue<ListNode* , vector<ListNode *>, cmp> myqueue;
    for(int i = 0; i<listArray.size();i++)
    {
        myqueue.push(listArray[i]);
    }
    while(!myqueue.empty())
    {
        auto smallest = myqueue.top();
        pTail->next =smallest;
        pTail=smallest;
        smallest=smallest->next;
        myqueue.pop();
        if(smallest)
        myqueue.push(smallest);
        
 
        
        // cout<<myqueue.top()->val<<endl;
        // myqueue.pop();
    }
    return pHead->next;
}


int main(int argc,char **argv)
{
    // vector<int>  array{1,1};
    // auto head= initNode(array);
    // // showNode(head);
    // // head=KgroupVerseRecursion(head,4);
    // // head = kGroupReverse(head,4);
    // cout<<isHuiwen(head)<<endl;
    //  showNode(head);


    vector<int> nums1{1,3,4};
    vector<int>nums2{2,4,6,8};
    vector<int>nums3{0};
    ListNode *l1 = initFromArray(nums1);
    ListNode *l2 = initFromArray(nums2);
    ListNode *l3 = initFromArray(nums3);
    // showNode(l3);
    vector<ListNode *> lists{l1,l2,l3};
    auto l4 = mergeKlistQueue(lists);
    showNode(l4);
}