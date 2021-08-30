#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
    {
    ListNode *l3 = new ListNode(0);
    ListNode *ltail = l3;
    int carry = 0;
    int remain =0;
    while(l1||l2)
    {
        int sum = 0;
        if(l1)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;  //加上进位
        remain = sum%10; //保留位
        ltail->next=new ListNode(remain);
        ltail=ltail->next;

        carry = sum/10; //进位
    }
    if(carry)  //最后看看还有没有进位
        ltail->next= new ListNode(carry);
     return l3->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    ListNode *l3 = new ListNode();
    ListNode *pTail3 = l3;

   
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    int carry = 0;
    int remain = 0;
    int i = 0;
    while (p1&&p2)
    {
    
       int val = carry+(p1->val)+(p2->val);
        remain = (val)%10;
        if(i ==  0)
        {
            l3->val=remain;
        }
        else
        {
        ListNode *pNew = new ListNode(remain);
        pTail3->next = pNew;
        pTail3=pNew;
        }
       carry = val/10;
       p1=p1->next;
       p2=p2->next;
       i+=1;
    }

    while (p1)
    {
        remain = (carry+p1->val)%10;
        ListNode *pNew = new ListNode(remain);
        pTail3->next = pNew;
        pTail3=pNew;
        carry=(carry+p1->val)/10;
        p1=p1->next;
    }

       while (p2)
    {
        remain = (carry+p2->val)%10;
        ListNode *pNew = new ListNode(remain);
        pTail3->next = pNew;
        pTail3=pNew;
        carry=(carry+p2->val)/10;
        p2=p2->next;
    }

    if(carry)
    {
        ListNode *pNew = new ListNode(carry);
        pTail3->next = pNew;
        pTail3=pNew; 
    }

    return l3;

    }
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


int main(int argc, char** argv)
{
    vector<int > array1={9,9,9,9,9,9,9};
    vector<int> array2={9,9,9,9};
    ListNode *l1 =NULL;
    ListNode *l2 =NULL;
    ListNode *l3 = NULL;
    initLinkList(l1,array1);
    initLinkList(l2,array2);
    Solution s;
    l3=s.addTwoNumbers2(l1,l2);
     show(l3);
 
    return 0;
}