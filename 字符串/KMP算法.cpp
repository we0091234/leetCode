#include <iostream>
#include <string>

using namespace std;
void getNext(string &str,int *nxt)  //获取nxt 数组
{
      int x= 1;
      nxt[0]=0;
      int now = 0;
      int k=1;
      while(x<str.size())
      {
          if(str[x]==str[now])
          {
              x+=1;
              now+=1;
              nxt[k++]=now;
          }
          else if(now)
          now = nxt[now-1];
          else if(!now)
          {
              nxt[k++]=0;
              x = x+1;
          }
          
      }
      
}

void  matchString(string str1,string str2)
{
    int *nxt = new int[str2.length()];
    getNext(str2,nxt);
    int len1 = str1.size(); 
    int len2 = str2.size();
    int tar = 0;
    int pos= 0;
    while(tar<len1)
    {
        if(str1[tar]==str2[pos])
        {
               tar+=1;
               pos+=1;
        }
        else if(pos)
        pos=nxt[pos-1];
        else if(!pos)
        tar+=1;

        if(pos==len2)
        {
            cout<<tar-pos<<endl;
            pos=nxt[pos-1];
        } 
    }
}

int main(int argc, char **argv)
{
    
    string myStr ="abcabdddabcabc";
    matchString(myStr,"abc");
    cout<<"haha"<<endl;
    return 0;
}