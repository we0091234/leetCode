#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char **argv)
{
    vector<int> nums{1,2,3,4,5,6,7,8,9,0};
    for(auto iter =nums.begin(); iter != nums.end();)
    {
        if(*iter %2 == 0)
        iter++;
        else
        iter = nums.erase(iter);
    }
    for(auto &s:nums)
    cout<<s<<" ";
    cout<<endl;
}