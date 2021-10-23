#include <iostream>
#include <vector>
#include <set>
using namespace std; 
void show(vector<int> &nums)
{
    for(auto &s :nums)
    cout<<s<<" ";
    cout<<endl;
}
void   func(vector<int> &nums)
{
    set<int> myset;
    for(int i = 0; i < nums.size(); i++)
    myset.insert(nums[i]);
    for(auto iter=myset.begin(); iter!=myset.end();iter++)
    cout<<*iter<<endl;
}

int main(int argc, char **argv)
{
    int num,num1;
    // cin>>num;
    vector<int> nums;
    
    // for(int i = 0; i<num; i++)
    // {
    //     cin>>num1;
    //     nums.push_back(num1);
    // }

    while(cin>>num1)
    {
        nums.push_back(num1);
    }
     num = nums[0];
    int i = 0;
    int j = 0;
    while(i<nums.size())
    {
        vector<int> result;
        num=nums[i];
        for(  j = 0; j<num; j++)
        {
           result.push_back(nums[i+1+j]);
        }
        i = i+j+1;
        func(result);
    }
    

}