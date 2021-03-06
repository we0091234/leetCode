#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool isHuiWen(string s,int left,int right)
{
    int length =(right-left+1) ;
    for(int i = left; i<left+length/2;i++)
    {
        if(s[i] != s[right+left-i])
        return false;   
    }
    return true;
}

string longestHuiWen(string s)// 暴力穷举1
{
    string tmp = "";
    int maxSub =0;
    for(int i = 0; i<s.length();i++)
    {
        for(int j =i; j<s.length();j++)
        {
            if (isHuiWen(s,i,j))
            {
                
                 if(maxSub<(j-i+1))
                 {
                     maxSub = j-i+1;
                    tmp = s.substr(i,j-i+1);
                 }
            }
        }
    }
   return tmp;
}


string longestHuiWen1(string s)// 暴力穷举2,j从后往前
{
    string tmp = "";
    int maxSub =0;
    for(int i = 0; i<s.length();i++)
    {
        for(int j =s.length(); j>=i;j--)
        {
            if (isHuiWen(s,i,j))
            {
                 if(maxSub<(j-i+1))
                 {
                     maxSub = j-i+1;
                    tmp = s.substr(i,j-i+1);
                 }
                 break;
            }
        }
    }
   return tmp;
}

string longestHuiWen2(string s)
{
    int flag =0;
    string tmp = "";
    for(int l = s.length();l>=1; l--)
    {
        int i=0,j = 0;
        while(j<s.length())
        {
            j =i+l-1;
            if(isHuiWen(s,i,j))
            {
                 tmp = s.substr(i,j-i+1);
                 return tmp;
            }
            i = i+1;
        }
    }
    return tmp;
}
void huiwenCenter(string s,int left,int right,int &max,string &subStr)
{
    while(left>=0 && right<s.length())
    {
        if(s[left]==s[right])
        {
           if (max <right-left+1)
           {
               max = right-left+1;
            subStr = s.substr(left,right-left+1);
           }
        }
        else
         break;
         left--;
         right++;
    }
}
string longestHuiWen3(string s)  //中心店向外扩散，分基数回文串，偶数回文串
{
    int max = 0;
    string subStr ="";
    for(int i = 0; i<s.length();i++)
    {
         huiwenCenter(s,i,i,max,subStr);  //奇数
        huiwenCenter(s,i,i+1,max,subStr); //偶数
    }
    return subStr;
    
}
string  getPalindrome(string s,int i, int j)
{
    string s1;
    while((i>=0 && j<=s.length()-1))
    {
        if(s[i]!=s[j])
        break;
        i--;j++;
    }
    s1 = s.substr(i+1,j-1-i);
    if(s1.length()>2)
    cout<<s1<<endl;
    return s1;
}
void longestPalindromeSubstring(string s)
{
    for(int i = 0; i<s.length();i++)
    {
        getPalindrome(s,i,i);
    }
}
string  longestPalindromeSubstring1(string s)
{
    string s1 = s;
    reverse(s1.begin(),s1.end());
    int len = s.size()+1;
    int maxlen= 0;
    int index = 0;
    string newstr;
    vector<vector<int>> dp(len,vector<int>(len,0));
    int i;
    for(i = 1; i<len; i++)
    {
        for(int j=1; j<len; j++)
        {
            if(s[i-1]==s1[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(maxlen<dp[i][j])
                {
                    
                    maxlen = dp[i][j];
                    index =i;
                    newstr = s.substr(i-maxlen,maxlen);
                    if(isHuiWen(newstr,0,newstr.size()-1))
                    {
                        index = i;
                         maxlen = dp[i][j];
                    }
                }
            }
        }
    }
    cout<<maxlen<<endl;
    return newstr;
    // return "haha";
    
}
int main(void)
{
    // cout<<isHuiWen("cbbd",1,2)<<endl;
    // cout<<longestHuiWen3("abacdefgfed")<<endl;
    // longestPalindromeSubstring("aba");
   cout<< longestPalindromeSubstring1("azbcza")<<endl;
    return 0;
}