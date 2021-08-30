#include <iostream>
#include <string>
#include <stack>
using namespace std;


   bool isValid(string s) 
   {
       stack<char> mystack;
       for(auto &str:s)
       {
           if(str=='('||str=='['||str=='{')
           mystack.push(str);
           else if(str==')'||str==']'||str=='}' )
           {
               if (mystack.empty())
               return false;
               char zuo = mystack.top();
               mystack.pop();
               if((str==')'&&zuo!='(') ||(str==']'&&zuo!='[') || (str=='}'&&zuo!='{'))
               return false;                 
           }
       }
       if(!mystack.empty())
       return false;
       return true;

    }



int main(void)
{
    cout<<isValid("{()[]}")<<endl;
    return 0;
}