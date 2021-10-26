#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string toBinary(int num)
{
  string result="";

  while(num)
  {
      string op = to_string(num%2);
      result+=op;
      num=num/2;
  }
  reverse(result.begin(),result.end());
  return result;
}

int max1(string str)
{
    int max =0;
    int index = 0;
    int state=0;
    for(int i = 0; i<=str.size(); i++)
    {
       if(str[i]=='0'||str[i]=='\0')
       {
           if(state==1)
           {
               int len =i-index;
               if (max<len)
               max = len;

           }
           state = 0;
       }
       else
       {
           if(state == 0)
           index = i;
           state =1;
       }

    }

    return max;
}

int main(void)
{
    int num =5;
    while(cin>>num)
    {
    cout<<max1(toBinary(num))<<endl;
    }
    return 0;
}