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
int sumVec(vector<int>& path)
{
    int sum =0;
    for (auto &s:path)
    sum+=s;
    return sum;
}

// void combination(int n, int k,int start)
// {
//     if(path.size()==k)
//     {
//         show(path);
//         return;
//     }
//     for(int i = start; i<=n; i++)
//     {
//          path.push_back(i);
//          combination(n,k,i+1);
//          path.pop_back();
//     }
// }

void combination2(int n, int k,int start)
{
    if(path.size()==k)
    {
        if(sumVec(path)==n)
        show(path);
        return;
    }
    for(int i = start; i<=9; i++)
    {
         path.push_back(i);
         combination2(n,k,i+1);
         path.pop_back();
    }
}



int main(int argc, char** argv)
{
    vector<int> l1{1,2,5};
    // cout<<sumVec(l1)<<endl;
    combination2(9,3,1);
    return 0;
}