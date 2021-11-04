#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

  double integerBreak(int n)  //普通做法
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

      double integerBreak1(int n)  //动态规划
   {
        vector<int> result(n+1);

        
      
      
   
    }

int main(int argc, char **argv)
{
    cout<< integerBreak1(7)<<endl;
    return 0;
}