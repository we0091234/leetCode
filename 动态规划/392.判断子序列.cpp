#include<iostream>
#include<vector>
#include <set>

using namespace std;

 int findLength(string s, string t) 
 {
     int m = s.size()+1;
     int n = t.size()+1;
     int maxEle= 0;
     vector<vector<int>>dp(m,vector<int>(n,0));
     for(int i = 0; i<n;i++)
     dp[0][i]=1;
     for(int i = 1; i<m;i++)
     {
           for(int j = 1; j<n; j++)
           {
           if(j<i)
           dp[i][j]=0;
           if(s[i-1]==t[j-1]&&dp[i-1][j]==1)
           dp[i][j]=1;
           else
           dp[i][j]=dp[i][j-1];

           }
     }

     return dp[m-1][n-1];

    }
int main(int argc, char** argv)
{
  string st1 = "aaaaaa";
  string st2 ="bbaaa";
  

    cout<<findLength(st1,st2)<<endl;
    return 0;
}