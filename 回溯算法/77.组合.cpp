#include <iostream>
#include <vector>
using namespace std;
vector<int> path;
void show(vector<int > path)
{
    for (auto &s:path)
    cout<<s<<" ";
    cout<<endl;
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



int main(int argc, char** argv)
{
    combination(4,3,1);
    return 0;
}