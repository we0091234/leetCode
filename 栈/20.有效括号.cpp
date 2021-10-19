#include <stack>
#include <iostream>
#include  <vector>
using namespace std;
    bool isValid(string s) 
    {
         stack<char >mystack;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            mystack.push(s[i]);
            else
            {
                if(mystack.empty())
                return false;
                char mystr = mystack.top();
                mystack.pop();
                if((s[i]==')'&&mystr!='(')||(s[i]==']'&&mystr!='[')||(s[i]=='}'&&mystr!='{'))
                return false;
            }
        }
        if(!mystack.empty())
        return false;
        return true;
    }

int main()
{
    cout<<isValid("()")<<endl;
}