
#include <iostream>
#include <vector>
#include <map>
using namespace std;


   int fib(int n)   //递归，有可能栈溢出
   {
        if(n==1 ||n==2)
        return 1;
        if(n==0)
        return 0;
        return fib(n-1)+fib(n-2);

    }
    int fib2(int n)
    {
        if (!n) return 0;
        if(n==1||n==2) return 1;
        int * nums = new int[n+1];
        nums[0]=0;
        nums[1]=nums[2]=1;
        for(int i = 3; i<=n;i++)
        {
            nums[i]=(nums[i-1]+nums[i-2])%1000000007;
        }
        return nums[n];
    }

int main(int argc, char **argv)
{
    vector<int> array{1,2,3,4,4};
    vector<int> MerGearray1{4,2,5,1};
    
    cout<<fib2(45)<<endl;
    return 0;
}

