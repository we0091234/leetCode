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


 bool strStr(string haystack, string needle)
  {
        vector<int> next = getNext(needle);
        int tar = 0;
        int pos= 0;
        int time=0;
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
                time+=1;
                if(tar!=haystack.size())
                pos=next[pos-1];
            }
        }
        
        if(time*needle.size()==haystack.size()&& pos==needle.size())
        {
            cout<<needle<<endl;
        return true;
        }

        return false;
    }



 bool repeatedSubstringPattern(string s) {

        
          
          auto result =  getNext(s);
          int be = 0;
          while(result[be]==0 && be<s.length()) be++;
          if(s.size()-be<be) return false;
          int be1= be;
          for(int i =1; i<=s.size()-be; i++)
          {
              if(result[be1]!=i)
              return false;
              be1++;
          }
          return  true;
          
         
    }

int main(int argc, char **argv)
{
    // string str1 ="";
    // string mstr="abcabdddabcabc";
    // cout<<str1.size()<<endl;
    cout<<repeatedSubstringPattern("abaababaab")<<endl;
    // cout<<strStr(mstr,"abcd");
    
    return 0;
}