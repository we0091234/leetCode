#include <iostream>
using namespace std;
template<typename T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode (T val):val(val) ,next(NULL){}

};

template<typename T>
class myStack
{
    public:
    ListNode<T> * top;
    myStack()
    {
        top =nullptr;
    }
    void push(T val)
    {
        auto newTop = new ListNode<T>(val);
        newTop->next =top;
        top =newTop;
    }
    T Top()
    {
        if (!isEmpty())
        return top->val;
        else
        {
        cout<<"Empty"<<endl;
        exit(0);
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"POP ERROR stack is empyt"<<endl;
            exit(0);
        }
        auto tmp = top;
        top=top->next;
        delete tmp;
    }
    bool isEmpty()
    {
        if (top == NULL)
        return true;
        return false;
    }
    void show()
    {
        auto p = top;
        while(p)
        {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    void clear()
    {
        if(!isEmpty())
        while(top)
        {
        auto tmp = top;
        top =top->next;
        delete tmp;
        }
        else
        {
            cout<<"mySt is empty"<<endl;
        }
       

    }

};

bool bracketMatching(string &s)
{
  myStack<char >myStr;
  for(int i = 0; i<s.length(); i++)
  {
      if(s[i]=='('||s[i]=='['||s[i]=='{')
      myStr.push(s[i]);
      if(s[i]==')'||s[i]==']'||s[i]=='}')
      {
          if(myStr.isEmpty())
          return false;
          char left = myStr.Top();
          myStr.pop();
          if((s[i]==')'&&left!='(')||(s[i]==']'&&left!='[')||(s[i]=='}'&&left!='{'))
          return false;
      }
  }
  if(!myStr.isEmpty())
  return false;
  return true;
}

int main(int argc, char**argv) {

 myStack<int> mySt;
 mySt.push(1);
  mySt.push(2);
   mySt.push(3);
   mySt.show();
   mySt.clear();
   mySt.show();
//    int val = mySt.Top();
//    cout<<val<<endl;
//    mySt.show();
//  cout<<mySt.isEmpty()<<endl;
// mySt.pop();

// mySt.pop();
// mySt.pop();
// mySt.pop();
// int val = mySt.Top();
// mySt.show();

return 0;
}