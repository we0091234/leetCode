#include <vector>
#include <iostream>
#include <string>

using namespace std;
vector<string> path;
bool isHuiwen(string &mystr)
{
    int i= 0,j = mystr.size()-1;
    while(i<j)
    {
        if(mystr[i]!=mystr[j])
        return false;
        i++;j--;
    }
    return true;
}
bool isHuiwenVec(vector<string>&mystrVec)
{
    for(auto &s :mystrVec)
    if(!isHuiwen(s))
    return false;
    return true;

}
void backTrace(string &mystr,int index,vector<vector<string>> &result)
{
    if(index>=mystr.size())
    {
        if(isHuiwenVec(path))
        result.push_back(path);
    return ;
    }
    for(int i = index; i<mystr.size(); i++)
    {
        path.push_back(mystr.substr( index,i-index+1));
        backTrace(mystr,i+1,result);
        path.pop_back();
    }
    
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
     backTrace(s,0,result);
     return result;
     
}

int main(int argc, char** argv)
{

   
    auto result=partition("aab");
    for(auto &s:result)
    {
    for (auto &c:s)
    cout<<c<<" ";
    cout<<endl;
    }
    return 0;
}