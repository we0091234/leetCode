#include <iostream>
#include <vector>
#include <string>
using namespace std;
std::vector<std::string> split(std::string str, std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str += pattern;//扩展字符串以方便操作
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        pos = str.find(pattern, i);
        if (pos < size)
        {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}


std::vector<std::string> split2(std::string str, char pattern)
{
    int index = 0;
    int state = 0;
    vector<string >result;
    for(int i = 0; i<=str.size(); i++)
    {
        if(str[i]==pattern || str[i]=='\0')
        {
            if(state==1)
             {
                 string mysub = str.substr(index,i-index);
                 result.push_back(mysub);
             }
             state = 0;
        }
        else
        {
            if(state ==0)
            index =i;
            state =1;
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    string  s ="wo shi sha bi";
    auto result = split2(s,' ');
    for(auto &s:result)
    cout<<s<<endl;
    return 0;
}