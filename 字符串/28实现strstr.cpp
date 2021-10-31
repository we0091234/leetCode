#include <iostream>
#include <string>
#include <vector>

using namespace std;
void show(vector<int> num)
{
    for(auto &s:num)
    {
        cout<<s<<" ";
    }
    cout<<endl;
}
vector<int> getNext(string needle)
{
    vector<int> result;
    result.reserve(needle.size());
    result.push_back(0);
    int x =1;
    int pos= 0;
    while(x<needle.size())
    {
        if(needle[x]==needle[pos])
        {
            pos+=1;
            x+=1;
            result.push_back(pos);
        }
        else if(pos)
        pos=result[pos-1];
        else if(!pos)
        {
            x+=1;
            result.push_back(0);
        }
    }
    return result;
}


 int strStr(string haystack, string needle)
  {
        vector<int> next = getNext(needle);
        int tar = 0;
        int pos= 0;
        while(tar<haystack.size())
        {
            if(haystack[tar]==needle[pos])
            {
                tar+=1;
                pos+=1;
            }
            else if(pos)
            pos=next[pos-1];
            else if(!pos)
            {
                tar+=1;
            }
            if(pos==needle.size())
            {
                return tar-pos;
            }
        }
        return -1;
    }


int main(int argc, char **argv)
{
    string str1 ="";
    string mstr="aa";
   auto result =  getNext(mstr);
   show(result);
    // cout<<strStr(mstr,"abcd");
    
    return 0;
}