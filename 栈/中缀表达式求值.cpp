#include <stack>
#include <iostream>
#include <map>

using namespace std;

void caculate(stack<double> &numstack,char op)
{
            double num1 =  numstack.top();
            numstack.pop();
            double num2 = numstack.top();
            numstack.pop();
            double num3;
            if(op=='*')
            {
                num3 = num1*num2;
            }
            else if(op=='+')
            {
                num3 = num1+num2;
            }
             else if(op=='/')
            {
                num3 = num2/num1;
            }
            else if(op=='-')
            {
                num3 = num2-num1;
            }
            numstack.push(num3);
}

float infixCalculation(string str)
{
     map<char ,int> myMap;
     myMap['+']=1;
     myMap['-']=1;
     myMap['*']=2;
     myMap['/']=2;
     myMap['(']=0;  //左括号优先级最小
     myMap[')']=0; 
    //  myMap[')']=2;
    stack<double> numstack;
    stack<char>opstack;
    int index= 0;
    int state = 0;
    for(int i = 0; i<=str.size(); i++)
    {
        int minsTate = 1;
        if(myMap.find(str[i])!=myMap.end()||str[i]=='\0')
        {
             if(str[i]=='-')                              //处理负数
            {
                if(i==0 || (i>0 && str[i-1]=='('))
                {
                    index = i;
                    state =1;
                    minsTate = 0;
                }
            }

            if(!minsTate) continue;

            if(state==1)
            {
            string  mystr = str.substr(index,i-index);
            numstack.push(atoi(mystr.c_str()));
            }
            state = 0;

             if(str[i]=='*'||str[i]=='+'||str[i]=='/'||str[i]=='-')   //遇到运算符先判断符号栈是否为空，然后再判断当前符号和栈顶符号的优先级
            {
                    while(!opstack.empty() &&(myMap[str[i]]<=myMap[opstack.top()]))
                    {
                         char op = opstack.top();
                         opstack.pop();
                        caculate(numstack,op);
                    }
                 opstack.push(str[i]);
            }
            else if(str[i]=='(')   //遇到左括号，就入栈
            opstack.push(str[i]);
            else if(str[i]==')')  //遇到右括号就全部出栈计算直到遇到左括号
            {
                char op;
                while((op=opstack.top())!='(')
                {
                    opstack.pop();
                    caculate(numstack,op);
                }
                opstack.pop();              //遇到了左括号，还要将左括号入栈
            }
        }
        else
        {
            if(state == 0)
           index = i;
           state=1;
        } 
    }
    while(!opstack.empty())
    {
        char op = opstack.top();
        opstack.pop();
        caculate(numstack,op);
    }
      return numstack.top();
}

int main(int argc, char ** argv)
{
    string mystr ="(-17+9)";
    cout<<infixCalculation(mystr)<<endl;
    return 0;
}