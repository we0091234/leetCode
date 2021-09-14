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

int main(int argc, char **argv)
{
    string  s ="i";
    auto result = split(s," ");
    for(auto &s:result)
    cout<<s<<endl;
    return 0;
}