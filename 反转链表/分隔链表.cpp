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
 ListNode* partition(ListNode* head, int x) 
 {
     ListNode* small = new ListNode(0);
     ListNode *big = new ListNode(0);
     ListNode *tmp = head;
     ListNode *bigTemp = big;
     ListNode *smallTmp =small;
     while(tmp)
     {
        if (tmp->val <x)
        {
            small->next = tmp;
            small=tmp;
        }
        else 
        {
            big->next = tmp;
            big=tmp;
        }
        tmp=tmp->next;
     }
     small->next=bigTemp->next;  //small的尾巴，指向big的头部
     big->next =NULL;     //big的尾巴指向NULL
     return small->next;  //返回的是small的头部，这样就串联起来
}

/*
说明:
1.定义两个指定，small和big，small用来串联小于x值的链表，big用来串联>=x值的链表，然后让small的尾部连接big的头部即可
2.最后  
*/

int main(int argc, char** argv)
{
    vector<int > array1={1,4,2,3,5,1};
    vector<int> array2={9,9,9,9};
    ListNode *l1 =NULL;
    ListNode *l2 =NULL;
    initLinkList(l1,array1);
    //  initLinkList(l2,array2);
     showNode(l1);
    auto l3= partition(l1,4);
    showNode(l1);
   
    
    return 0;
}