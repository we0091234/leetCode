#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
    string removeDuplicates(string s) 
    {
        stack<char> mystack;
        string tmp ="";
        for(int i = 0; i<s.size(); i++)
        {
            if(!mystack.empty())
            {
                char tmp= mystack.top();
                if(s[i]==tmp)
                {
                mystack.pop();
                continue;
                }
            }
            mystack.push(s[i]);
        }
        while(!mystack.empty())
        {
            tmp+=mystack.top();
            mystack.pop();
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }

int main(int argc, char ** argv)
{
    cout<<removeDuplicates("abbaca")<<endl;
    return 0;
}