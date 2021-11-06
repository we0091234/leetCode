#include <iostream>
#include <string>
#include <vector>

using namespace std;
void show(vector<int> nums)
{
    for (auto &s:nums)
    cout<<s<<" ";
    cout<<endl;
}

vector<int> getNext(string str)
{
    vector<int> next(str.size(),0);
    next[0]=0;
    int i = 1;
    int pos=0;
    while(i<str.size())
    {
        if(str[pos]==str[i])
        {
            next[i++]=++pos;
        }
        else if(pos)
        pos = next[pos-1];
        else
        {
            next[i++]=0;
        }
    }
    return  next;
}

void pipei(string oristr,string substr)
{
    int len1 = oristr.length();
    int len2 = substr.length();
    auto next = getNext(substr);
    int tar = 0;
    int pos= 0;
    while(tar<len1)
    {
        if(oristr[tar]==substr[pos])
        {
            tar++;pos++;
        }
        else if(pos)
        pos=next[pos-1];
        else
        {
            tar = tar+1;
        }
        if(pos==len2)
        {
            cout<<tar-pos<<endl;
            pos= next[pos-1];
        }
        
    }
}

int main(int argc, char **argv)
{
    string mystr="aabababaaaaaaaaaaaabaaaa";
    string mystr2 = "aa";
    pipei(mystr,mystr2);
  
    return 0;
}