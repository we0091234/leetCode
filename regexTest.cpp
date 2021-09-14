#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
using namespace std;
int main()
{
    // string mystr ="prob_1 slkjf slkdjf slkdj prob_2 prob_ab prob_12 ";
   

    ifstream in("/home/xiaolei/leetCodeNew/leetCode/NoStdVehicle.prototxt",ios::in);
    std::stringstream buffer;  
    buffer << in.rdbuf();  
    std::string contents(buffer.str());
    // cout<<contents<<std::endl;
    //  string pattern("(top:.+)(prob_[\\d|\\w]+)");
    //  inner_product_param {
    // num_output: 11
    string pattern("num_output:.+[\\d]+");
    std::regex r(pattern);
     for (std::sregex_iterator it(contents.begin(), contents.end(), r), end;     //end是尾后迭代器，regex_iterator是regex_iterator的string类型的版本
        it != end;
        ++it)
    {
        std::cout << it->str()<< std::endl;
    }

    return 0;
}