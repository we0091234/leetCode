  #include <stdio.h>
#include <iostream>
#include <vector>
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

   ListNode* oddEvenList(ListNode* head) 
   {
      
       if(head == NULL || head->next == NULL)
       return head;
       
       auto even = head;  //定义双链表，even 奇链表，和odd偶链表的头，最后将奇链表的尾巴，指向偶链表的头即可
       auto odd = head->next;
       auto evenTail =even;
       auto oddTail = odd;
       auto p = oddTail->next;
       int val = 3;
       while(p)
       {
           if (val%2)
           {
           evenTail->next =p;
           evenTail = p;
           }
           else
           {
            oddTail->next =p;
            oddTail = p;
           }

            val+=1;
            
           p = p->next;
          
       }

      oddTail->next =NULL;
       evenTail->next=odd;

       return  even;
      

    }

      vector<ListNode*> splitListToParts(ListNode* head, int k) {
          int length = 0;
          auto p = head;
          int newRemain = 1;
          ListNode *pHead = new ListNode(-1);
          pHead->next = head;
          auto  pre=pHead;
          auto cur = pHead->next;
          vector<ListNode*> result;
          while(p)
          {
              length+=1;
              p = p->next;
          }
          int  remain = length%k;   //前几块多一个，比如1,2,3,4,5,6 分四块 6%4=2，那么意思就是前两块每一块都多一个，变为[1,2][3,4][5][6]正好四块，这里前两块比后两块多一个
          int  ori = length/k;      //每一块的长度为多少
          for(int i = 0; i<k&&cur; i++)
          {
              pre =pHead;
              pre->next =cur;
              
              if(i>=remain)
              {
                  newRemain=0;
              }
              
                result.push_back(cur);
              
              for(int j = 0; j<ori+newRemain; j++ )
              {
                 cur = cur->next;
                 pre=pre->next;
              }
                

            //   pHead->next =cur;
              pre->next = NULL;

             
          }
        


        return result;

    }

int main(int argc,char **argv)
{
    vector<int>  array{1, 2, 3};
    auto head= initNode(array);
    // showNode(head);
     auto result = splitListToParts(head,5);
     int count = 0;
     for(auto &s:result)
     {
         showNode(s);
        count++;
     }
     cout<<count<<endl;

    //  showNode(head);
}
  
  
  
  
  
  
  
  
  