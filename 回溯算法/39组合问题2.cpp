#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void show(vector<int > path)
{
    for (auto &s:path)
    cout<<s<<" ";
    cout<<endl;
}
int sumVec(vector<int>& path)
{
    int sum =0;
    for (auto &s:path)
    sum+=s;
    return sum;
}


void combination(int n, int k,int start)
{
    if(path.size()==k)
    {
        show(path);
        return;
    }
    for(int i = start; i<=n; i++)
    {
         path.push_back(i);
         combination(n,k,i+1);
         path.pop_back();
    }
}

void combination2(int n, int k,int start)
{
    if(path.size()==k)
    {
        show(path);
        return;
    }
    for(int i = start; i<=n; i++)
    {
         path.push_back(i);
         combination(n,k,i+1);
         path.pop_back();
    }
}

void combinationSum(vector<int>& candidates, int target,int index,vector<bool>& used)
  {
      if(sumVec(path)==target)
      {
        show(path);
      return ;
      }
      if(sumVec(path)>target)
      {
        
      return ;
      }
      
      for(int i = index; i<candidates.size(); i++)
      {
          if(i>0 && candidates[i-1]==candidates[i])
          continue;
          path.push_back(candidates[i]);
          used[i]=true;
          combinationSum(candidates,target,i+1,used);
          path.pop_back();
          used[i]=false;
      }
    
}



int main(int argc, char** argv)
{
    vector<int> nums{10,1,2,7,6,1,5};
    sort(nums.begin(),nums.end());
    vector<bool> used(nums.size(),false);
    int target =8;
    combinationSum(nums,target,0,used);
    return 0;
}