#include <string>
#include <iostream>
using namespace std;


void reverseStr(string &s,int start,int end)
{
    int i = start;
    int j = end;
    while(i<j)
    {
        auto tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;j--;
    }

}

string reverseLeftWords(string s, int n) 
{ 

    reverseStr(s,0,s.size()-1);
    reverseStr(s,0,s.size()-1-n);
    reverseStr(s,s.size()-n,s.size()-1);

    return s;

}

int main(int argc, char **argv)
{
    cout<<reverseLeftWords("abcdef",2)<<endl;
    return 0;
}