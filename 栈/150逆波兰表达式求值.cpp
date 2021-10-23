#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
 int evalRPN(vector<string>& tokens) {
     stack<int> mystack;
     for(int i = 0; i<tokens.size(); i++) 
     {
         if ((tokens[i]=="+")||(tokens[i]=="-")||(tokens[i]=="*")||(tokens[i]=="/"))
         {
             if(tokens[i]=="+")
             {
                 int val1 = mystack.top();
                 mystack.pop();
                 int val2 = mystack.top();
                 mystack.pop();
                 int res = val1 + val2;
                 mystack.push(res);
             }
             else if(tokens[i]=="-")
             {
                 int val1 = mystack.top();
                 mystack.pop();
                 int val2 = mystack.top();
                 mystack.pop();
                 int res = val2 - val1;
                 mystack.push(res);
             }
             else if(tokens[i]=="*")
             {
                 int val1 = mystack.top();
                 mystack.pop();
                 int val2 = mystack.top();
                 mystack.pop();
                 int res = val1 * val2;
                 mystack.push(res);
             }
             else if(tokens[i]=="/")
             {
                 int val1 = mystack.top();
                 mystack.pop();
                 int val2 = mystack.top();
                 mystack.pop();
                 int res = val2 / val1;
                 mystack.push(res);
             }
         }
         else
         mystack.push(atoi(tokens[i].c_str()));
     }
          return mystack.top();
    }

int main(int argc, char ** argv)
{
   vector<string>tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
   cout<<evalRPN(tokens)<<endl;
    return 0;
}