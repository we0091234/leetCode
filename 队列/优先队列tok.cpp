#include <iostream>
#include <queue>
using namespace std;
void showArray(vector<int> &nums)
{
    for(auto &s:nums)
    cout<<s<<" ";
    cout<<endl;
}


int main(int argc, char **argv)            //最小k个数
{
    vector<int > nums{1,3,2,4,0};
    int k=3;
    priority_queue<int,vector<int> ,less<int> > myQueue;
    for(int i = 0; i<k; i++)
    {
        myQueue.push(nums[i]);
    }
    for(int i = k; i<nums.size(); i++)
    {
        if(nums[i]<myQueue.top())
        {
            myQueue.pop();
            myQueue.push(nums[i]);
        }
    }

    while(!myQueue.empty())
    {
        cout<<myQueue.top()<<endl;
        myQueue.pop();
    }
    return 0;
}