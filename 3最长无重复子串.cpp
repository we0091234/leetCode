#include <iostream>
#include <string>
#include <string.h>
#include <unordered_set>
#include <map>
#include <string.h>
using namespace std;
  int lengthOfLongestSubstring(string s)  //我自己的实现
   {
       int index1 = 0;
       int flag =0;
       int maxLength = 0;
       const char * sr=s.c_str();
       int i = 0;
       for( i = 0; i<strlen(sr); i++)
       {
           for(int j = index1; j<i;j++)  //每增加一个字符，就要和之前的字符进行对比，是否有重复
           {
                 if(sr[j]==sr[i])         //如果有重复的那么标志为1 
                 {
                     flag = 1;
                     break;
                 }
           }
           if (flag)   //代表有重复
           {
              maxLength = max(maxLength,i-index1); //那么当前的不重复子串的程度就为i-index1,然后和之前的子串取最大值
              index1=index1+1;                    //将index=index+1，寻找下一个不重复的子串
              i = i-1;                // i要向后面退一个
              flag = 0;           //标志位重新设置为0
           }
       }
       if(i == strlen(sr) && flag==0)       //针对如果找不到重复字符的话，那么flag永远不会为1，那么maxlength就永远为0，所以增加一个判断
       {
           maxLength = max(maxLength,i-index1);
       }
    
       return maxLength;
    }

     int lengthOfLongestSubstring1(string s) //参考他人实现
     {
         const char *sr = s.c_str();
         unordered_set<char >myset;
         int start=0,end = 0;
         int maxl =0;
         while (end <strlen(sr))
         {
            if(myset.find(sr[end])!=myset.end())
            {
                 myset.erase(myset.find(sr[start]));
                 start+=1;
            }
            else
            {
                myset.insert(sr[end++]);
                if (maxl<myset.size());
                maxl=myset.size();
                // maxl=std::max(maxl,myset.size());
            }
         }
         return maxl;
     }  
int   lengthOfLongestSubstring2(string s)  //参考他人实现2
{
    int i=0,j=0;
    map<char,int> mymap;
    int max= 0;

    for(j = 0; j<s.length();j++)
    {
        auto iter = mymap.find(s[j]);

        if(iter!=mymap.end())
        {
            i =std::max(i,mymap[s[j]]);  //直接转移到不重复的下一个，比如abcdccb  ,初始i=0,在j移动到第二个c时，此时i直接移动到d。因为abcdc,bcdc,cdc,都是重复的只有dc才不重复。
        } 
            max = std::max(max,j-i+1);
            mymap[s[j]]=j+1; 
    }
    return max;
    
}


int   lengthOfLongestSubstring3(string s)  //参考他人实现3
{
    int i=0,j=0;
    map<char,int> mymap;
    int  a[128]={0};
    int maxl= 0;
    for(j = 0; j<s.length();j++)
    {
        i =std::max(i,a[s[j]]);
        maxl = std::max(maxl,j-i+1);
       a[s[j]]=j+1;
    }
    return maxl;
}

int zuichangwuchognfuzichuan(string s) //my 
{
    int a[256]={0};
    int i = 0,j = 0;
    int max= 0;
    for(; j<s.length();j++)
    {
       if(a[s[j]]!=0)
       {
          i = std::max(i,a[s[j]]);
       }
           max = std::max(max,j-i+1);
           a[s[j]]=j+1;
    }
    return max;
    
}

int main(int argc, char ** argv)
{
    cout<<zuichangwuchognfuzichuan("abcdefab")<<endl;
    return 0;
}