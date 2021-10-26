#include <iostream>
#include <string>

using namespace std;
void splitNum(string s)
{
    int index = 0;
    int state = 0;
    
    for(int i = 0; i<=s.size(); i++)
    {
        int minsTate = 1;
         if(s[i]=='-')
            {
                if(i==0 || (i>0 && s[i-1]=='('))
                {
                    index = i;
                    state =1;
                    minsTate = 0;
                }
            }

           if(!minsTate) continue;

        if(s[i]=='-'||s[i]==')'||s[i]=='*'||s[i]=='('||s[i]=='+')
        {
           
                 if(state ==1)
                {
                    auto mystr = s.substr(index,i-index);
                    cout<<mystr<<endl;
                }
                state = 0;
            
        }
        else
        {
            if(state==0)
            index =i;
            state =1;
        }
    }
}

int main(int argc, char **argv)
{
    string mystr="-1*(-1-1)*(-13+4)-14";
    splitNum(mystr);
    return 0;
}