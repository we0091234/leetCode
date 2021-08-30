#include <iostream>
#include <string>
#include <string.h>
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

int main(void)
{
    // cout<<isHuiWen("cbbd",1,2)<<endl;
    // cout<<longestHuiWen3("abacdefgfed")<<endl;
    cout<<longestHuiWen3("ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy")<<endl;
    return 0;
}