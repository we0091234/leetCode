#include <iostream>
using namespace std;
 int reverse(int    x) {
     int sum = 0;
   int intMAX = 2147483647 , intMin = -2147483648;
    
     
        while (x)
        {
            int re = x%10;
            if ((sum>intMAX/10)||sum<intMin/10)
            return 0;
            sum=sum*10+re;
            x=x/10;
        }
     

       return sum;
    }


int main(void )
{
    int   a =-153423646;
    cout<<reverse(a)<<endl;
    return 0;
}