#include <iostream>
#include <queue>
  //一个队列完成栈
using namespace std;
class MyStack {
public:
    queue<int> myQueue;
    MyStack() {

    }
    
    void push(int x) {
        myQueue.push(x);

    }
    
    int pop() {
        int size = myQueue.size();   // 比如1,2,3,4  首先变为4,1,2,3 那么4变为队列首元素，出队列，相当于4先出，所以实现了栈的操作
        size=size-1;
        while(size>0)
        {
            int val = myQueue.front();
            myQueue.pop();
            myQueue.push(val);
            size--;
        }
        int val = myQueue.front();
        myQueue.pop();
        return val;

    }
    
    int top() {
        int size = myQueue.size();
        size=size-1;
        while(size>0)
        {
            int val = myQueue.front();
            myQueue.pop();
            myQueue.push(val);
            size--;
        }
        int val = myQueue.front();
        myQueue.pop();
        myQueue.push(val);
        return val;

    }
    
    bool empty() {
        return myQueue.empty();

    }
};


int main()
{
    MyStack mystack;
    for(int i = 0; i<4; i++)
    mystack.push(i);
    while(!mystack.empty())
    {
        cout<<mystack.top()<<endl;
        mystack.pop();
        
    }
}