#include <iostream>
#include<string>

using namespace std;

int getScore(string s)
{
    int digit = 0;
    int lowerLetter = 0;
    int bigLetter = 0;
    int other = 0;
    int score = 0;
    int len = s.size();
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        digit++;
        else if(s[i]>='a'&&s[i]<='z')
        lowerLetter++;
        else if(s[i]>='A'&&s[i]<='Z')
        bigLetter++;
        else
        other++;
    }
    if(len<=4)
    score+=5;
    else if(len<=7)
    score+=10;
    else if(len>=8)
    score+=25;
  

    int n = bigLetter+lowerLetter;
    if(n==0)
    score+=0;
    else if(bigLetter==0|| lowerLetter==0)
    score+=10;
    else if(bigLetter!=0&&lowerLetter!=0)
    score+=20;

      if(digit==0)
    score+=0;
    else if(digit==1)
    score+=10;
    else if(digit>1)
    score+=20;

       if(other==0)
    score+=0;
    else if(other==1)
    score+=10;
    else if(other>1)
    score+=25;

    if(lowerLetter!=0&&bigLetter!=0&&digit!=0&&other!=0)
    score+=5;
    else if(n!=0 && digit!=0 &&other!=0)
    score+=3;
    else if(n!=0 && digit!=0)
    score+=2;

  return score;

}
int main(int argc, char **argv)
{

    string mystr;
    while(cin>>mystr)
    {
        int score = getScore(mystr);
        if(score>=90)
        cout<<"VERY_SECURE"<<endl;
        else if(score>=80)
          cout<<"SECURE"<<endl;
          else if(score>=70)
          cout<<"VERY_STRONG"<<endl;
          else if(score>=60)
          cout<<"STRONG"<<endl;
          else if(score>=50)
          cout<<"AVERAGE"<<endl;
              else if(score>=25)
          cout<<"WEAK"<<endl;
          else
          cout<<"VERY_WEAK"<<endl;


    }

    return 0;
}