#include <iostream>
#include <string>

using namespace std;
int  isHuiwen(int index1,int index2,string s)
{
    int i =index1,j=index2;
    int count=0;
    while(i>=0&&j<s.size())
    {
        if(s[i]!=s[j])
        break;
        i--;j++;
        count++;
    }
    return count;
    
}
int subHuiwen(string s)
{
    int sum= 0;
    for(int i = 0; i<s.size(); i++)
    {
        sum+=(isHuiwen(i,i+1,s)+isHuiwen(i,i,s));
     
    }
    return sum;
}


int main(int argc, char **argv)
{
    string str="abc";
   cout<< subHuiwen(str)<<endl;
    return 0;
}