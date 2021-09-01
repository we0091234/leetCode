  #include <iostream>
  #include <string>
  #include <vector>
  using namespace std;
  
  string replaceSpace(string s) {
      vector<string> split;
       s[0]='w';
       return s;
    }


int main(int argc,char **argv)
{
    string s = "We are happy";
    s = replaceSpace(s);
    cout<<s<<endl;
}