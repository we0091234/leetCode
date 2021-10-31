#include <iostream>
#include <string>
using namespace std;
   bool  isPalindrome(int x) {      //用字符串
       auto s = to_string(x);
       for(int i = 0; i<s.length()/2;i++)
       {
           if(!(s[i]==s[s.length()-1-i]))
           return false;
       }
           return true;
    }

     bool  isPalindrome1(int x) {        //不用字符串
       if(x<0) return false;
       int sum = 0;
        int ori =x;
        int intMAX = 2147483647 , intMin = -2147483648;
        while(x)
        {
            sum = sum*10+x%10;
            if (sum>intMAX/10 && x>=10)
            return false;
            x=x/10;
        }
        if(sum == ori)
           return true;
        return false;
    }

int main(void)
{
    cout<<isPalindrome1(1000000001)<<endl;;
    return 0;
}