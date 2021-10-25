#include <stack>
#include <iostream>
#include <map>

using namespace std;
float infixCalculation(string str)
{
     map<char ,int> myMap;
     myMap['+']=1;
     myMap['-']=1;
     myMap['*']=2;
     myMap['/']=2;
     myMap['(']=2;
     myMap[')']=2;
    stack<int> numstack;
    stack<char>opstack;
    int index= 0;
    int state = 0;
    for(int i = 0; i<=str.size(); i++)
    {
        if(myMap.find(str[i])!=myMap.end()||str[i]=='\0')
        {
            if(state==1)
            {
            string  mystr = str.substr(index,i-index);
            numstack.push(atoi(mystr.c_str()));
            }
            state = 0;

             if(myMap.find(str[i])!=myMap.end())
            {
                // if(!opstack.empty() && (myMap[str[i]]>myMap[opstack.top()]))
                // opstack.push(str[i]);
                // else if(opstack.empty())
                // {
                //     opstack.push(str[i]);
                // }
                // else 
             
                if(str[i]==')')
                {
                    while(true)
                    {
                        int num1 =  numstack.top();
                        numstack.pop();
                        int num2 = numstack.top();
                        numstack.pop();
                        int num3;
                        char op = opstack.top();
                        if(op=='(') 
                        {
                            opstack.pop();
                        break;
                        }
                        opstack.pop();
                        if(op=='*')
                        {
                            num3 = num1*num2;
                        }
                        if(op=='+')
                        {
                            num3 = num1+num2;
                        }
                        numstack.push(num3);
                    }
                }
                else if(!opstack.empty() &&(myMap[str[i]]<=myMap[opstack.top()]&&str[i]!='('))
                {
                    while(!opstack.empty() &&(myMap[str[i]]<=myMap[opstack.top()]))
                    {
                        int num1 =  numstack.top();
                        numstack.pop();
                        int num2 = numstack.top();
                        numstack.pop();
                        int num3;
                        char op = opstack.top();
                        opstack.pop();
                        if(op=='*')
                        {
                            num3 = num1*num2;
                        }
                        if(op=='+')
                        {
                            num3 = num1+num2;
                        }
                        numstack.push(num3);
                    }
                   
                }
                if(str[i]!=')')
                 opstack.push(str[i]);
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
           int num1 =  numstack.top();
            numstack.pop();
            int num2 = numstack.top();
            numstack.pop();
            int num3;
            char op = opstack.top();
            opstack.pop();
            if(op=='*')
            {
                num3 = num1*num2;
            }
            if(op=='+')
            {
                num3 = num1+num2;
            }
            numstack.push(num3);
    }
      return numstack.top();
}

int main(int argc, char ** argv)
{
    string mystr ="30*(20+5)";
    cout<<infixCalculation(mystr)<<endl;
    return 0;
}