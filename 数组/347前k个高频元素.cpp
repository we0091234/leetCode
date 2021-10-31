#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
void show(vector<int> nums)
{
    for(auto &s:nums)
    cout<<s<<" ";
    cout<<endl;
}
struct myArray
{
    int val;
    int count;
};
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
             return a.second > b.second;
    }
};

  vector<int> topKFrequent(vector<int>& nums, int k) 
  {
      vector<int> result;
     map<int,int > myMap;
      for(int i = 0; i<nums.size(); i++)
 myMap[nums[i]]+=1;
 
vector<pair<int, int >> myVecPair;
for(auto iter = myMap.begin(); iter != myMap.end();iter++)
{
    auto newPari = make_pair(iter->first,iter->second);
    myVecPair.push_back(newPari);
}

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> myQueue;
for(int i = 0; i<k; i++)
{
    myQueue.push(myVecPair[i]);
}
for(int  i = k; i<myVecPair.size(); i++)
{
    auto tmp = myQueue.top();
    if(myVecPair[i].second>tmp.second)
    {
    myQueue.pop();
    myQueue.push(myVecPair[i]);
    }
}

while(!myQueue.empty())
{
    auto tmp =myQueue.top();
    result.push_back(tmp.first);
    myQueue.pop();
}

return result;
    }


int main(int argc, char** argv)
{
    
vector<int> nums{1,1,1,1,1,1,1,1,1,3,3,3,3,2,2};
auto result =topKFrequent(nums,1);
show(result);
 
    return 0;
}