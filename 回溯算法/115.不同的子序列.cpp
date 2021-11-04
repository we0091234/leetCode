#include<iostream>
#include <vector>
#include <string>
using namespace std;
string path="";
void backTrace(string s,string t,int index,int &number)
{
   if(path==t)
   {
       number+=1;
   }
   for(int i = index; i<s.size();i++)
   {
       if(path.size()>t.size())
       continue;
       path+=s[i];
       backTrace(s,t,i+1,number);
       path.pop_back();
   }
}

 int numDistinct(string s, string t)
  {
        int number = 0;
        backTrace(s,t,0,number);
        return number;
    }


int main(int argc, char** argv)
{
    string s1 ="babgbaga";
    string s2 = "ba";
     cout<<numDistinct(s1,s2)<<endl;

 
}