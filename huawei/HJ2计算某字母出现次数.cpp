#include <string>
#include <iostream>
#include <string.h>
using namespace std; 
int chrTime(char *mystr,char chr)
{
     int array[256]={0};
     for(int i = 0; i<strlen(mystr);i++)
     {
         array[mystr[i]]+=1;
     }
     return array[chr];
    
}
char big2lower(char mychar)
{
    if(mychar >='A'&&mychar <='Z')
    mychar+=32;
    return mychar;
}


int main(int argc, char **argv)
{
    char mystr[1024];
    cin.getline(mystr, 1024);
    char mychr;
    cin>>mychr;

    for(int i = 0;i<strlen(mystr);i++)
    mystr[i]=big2lower(mystr[i]);

    mychr = big2lower(mychr);

    cout<<chrTime(mystr,mychr)<<endl;
    return 0;
}