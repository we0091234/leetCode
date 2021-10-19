#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class myQueue
{
    private :
stack<int> myStackIn;
stack<int> myStackOut;
public:

void push(int val)
{
    while (!myStackOut.empty())
    {
       auto top = myStackOut.top();
       myStackOut.pop();
       myStackIn.push(top);
    }
     myStackIn.push(val);
}
int pop()
{
     while(!myStackIn.empty())
    {
       auto top = myStackIn.top();
       myStackIn.pop();
       myStackOut.push(top);
    }
    int val = myStackOut.top();
    myStackOut.pop();
    return  val;
}
bool empty()
{
    if(myStackIn.empty()&&myStackOut.empty())
    return true;
    return false;
}
int peek()
{
      while(!myStackIn.empty())
    {
       auto top = myStackIn.top();
       myStackIn.pop();
       myStackOut.push(top);
    }
    int val = myStackOut.top();
    return val;
}

};


int main(int argc, char ** argv)
{
    myQueue myque;

    for(int i = 0; i<5; i++)
    {
        myque.push(i);
    }

    while(!myque.empty())
    {
        cout<<myque.peek()<<endl;
        myque.pop();
    }
    return 0;
}