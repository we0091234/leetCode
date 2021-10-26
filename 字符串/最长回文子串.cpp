#include <iostream>
#include <string>

using namespace std;

string   longestPalindromeSubstring(string &s,int st1,int st2)
{
      int i = st1,j=st2;
      while(i>=0&&j<s.size())
      {
          if(s[i]!=s[j])
          break;
          i--;j++;
      }
      i++;j--;
      return s.substr(i,j-i+1);
}


int main(int argc, char **argv)
{
   string mystr = "cdabbacc";
   int max = 0;
   for(int i = 0; i<mystr.size(); i++)
   {
       int len=longestPalindromeSubstring(mystr,i,i).size();
       if(max<len)
       max = len;
       len = longestPalindromeSubstring(mystr,i,i+1).size();
       if(max<len)
       max = len;
   }
   cout<<max<<endl;
   
}