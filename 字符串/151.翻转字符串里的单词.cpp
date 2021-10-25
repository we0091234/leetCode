#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std; //



vector<string> strSplit(string &s)
{
    string oriSub = s;
    vector<string> result;
    int loc;
    while((loc=oriSub.find(" "))!=string::npos)
    {
    string mysub = oriSub.substr(0,loc);
     oriSub = oriSub.substr(loc+1);
     if (mysub.size()<1)
     continue;
     result.push_back(mysub);
    }
     if (oriSub.size()>=1)
  result.push_back(oriSub);
  reverse(result.begin(),result.end());
  return result;
}

 string reverseWords(string s) {

    string newResult = "";
    auto result =  strSplit(s);

    for (int i = 0; i<result.size(); i++) 
    {
        if(i==result.size()-1)
        newResult +=result[i];
        else
        newResult +=result[i]+" ";
    }
    
        return newResult;
    }


void reverseMystr(string &str,int left,int right)
 {        

     int i =left,j = right;
     while(i<j)
     {
         auto tmp = str[i];
         str[i]=str[j];
         str[j]=tmp;
         i++;j--;
     }

 }
 void deleteSpace(string &s) ;

 string reverseWords1(string s)  //思路 首先将字符串整体反转，比如hello world  变为dlrow olleh  然后针对每一个单词进行反转，
 {
//   deleteSpace(s);
deleteSpace(s);

    reverseMystr(s,0,s.size()-1);     
       
    int index1= 0;
    int index2= 0;
    int state = 0;
    for(int i = 0; i<=s.size(); i++)
    {
        if(s[i]==' '||s[i]=='\0')
        {
          if (state==0)
          reverseMystr(s,index1,i-1);
       

            state=1;

        }
        else
        {
            if(state==1)
            index1 = i;
            state = 0;

        }
    }
    //   stripSpace(s);
      
    return s;
 }

void deleteSpace(string &s)   //去除连续空格的多余空格，保留一个空格
{
    for(int i = 0; i<strlen(s.c_str()); i++)
    {
        if(s[i]==' ')
        {
            int k = i;
            int numofSpace = 0;
            while(s[k]==' ') 
            {k++;numofSpace++;}
                if(i!=0)
                 s.erase(i,numofSpace-1);
                else
                s.erase(i,numofSpace);
        }
    }
    int j = strlen(s.c_str())-1;
     int numofSpace = 0;
    while(s[j]==' ') 
    {j --;
    numofSpace+=1;
    }
    s.erase(j+1,numofSpace);
}
    

int main(int argc, char **argv)
{
    string str = " hello   world";
   
    cout<<reverseWords1(str)<<endl;
    
    
    return 0;
}