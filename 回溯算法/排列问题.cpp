#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> path;
void show(vector<int > path)
{
    for (auto &s:path)
    cout<<s<<" ";
    cout<<endl;
}

bool findKey(vector<int>&path ,int key)
{
   

	if (std::find(path.begin(), path.end(), key)!=path.end())
		return 1;
	else
		return 0;

}

void arrangement(int n, int k)  //排列
{
    if(path.size()==k)
    {
        show(path);
        return;
    }
    for(int i = 1; i<=n; i++)
    {
        if(!findKey(path,i))
        {
         path.push_back(i);
         arrangement(n,k);
         path.pop_back();
        }
    }
}




int main(int argc, char** argv)
{
    arrangement(4,3);
    // 
    // vector<int> nums{1,2};
    // cout<<findKey(nums,3)<<endl;
    return 0;
}