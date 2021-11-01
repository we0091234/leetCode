#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

  double integerBreak(int n)
   {
      
      int numof3 = n/3;
      int remain = n%3;
      if(remain==1)
      {
          remain =4;
          numof3=numof3-1;
      }

      double result = pow(3,numof3);
      result=result*remain;
      
    return result;
    }

int main(int argc, char **argv)
{
    cout<< integerBreak(7)<<endl;
    return 0;
}