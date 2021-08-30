
/*
说明 此题用栈解决，当遇到左括号的时候，入栈，然后遇到右括号的时候，栈顶元素出栈，判断栈顶元素和这个右括号是否匹配：
1：不匹配 直接返回false
2: 匹配的话，接着判断下一个括号
3：如果碰到右括号还有，而栈为空的话，那么代表右括号多了，直接返回false 比如 （))  
4：如果碰到右括号匹配完毕，而栈元素还有，那么代表坐括号多了，比如(()

*/
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

bool isValid(string s) 
{
    stack<char> mystack;
    int flag= 1;
    int i = 0;
    for (auto &mystr:s)
    {
        if(mystr==')'||mystr==']'||mystr=='}')
        {
           if(!mystack.empty())
           {
               auto pi = mystack.top();
               if((mystr==')'&&pi!='(') || (mystr==']'&&pi!='[') || (mystr=='}'&&pi!='{'))  //说明不匹配
                    return false;
               mystack.pop();    //栈顶元素出栈
           }
           else               //空的话说明右括号多了
            return false;
        }
        else if (mystr=='('||mystr=='['||mystr=='{') //左括号才入栈
        mystack.push(mystr);
    }
    return mystack.empty();  //如果不为空的话，说明左括号多了比如 (() 
    }

int main(int argc, char ** argv)
{
    cout<<isValid("{{[()]}}")<<endl;;
    return 0;
}