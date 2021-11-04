#include <iostream>
#include<string>
#include <vector>
using namespace std;

 int numDistinct(string s, string t)
  {
       int m =t.size()+1;
       int n = s.size()+1;
       vector<vector<unsigned int>> dp(m,vector<unsigned int>(n,0));
       for(int i = 1; i<n; i++)
       {
           if(s[i-1]==t[0])
           dp[1][i]=dp[1][i-1]+1;
           else
           dp[1][i]=dp[1][i-1];
       }

       for(int i =2;i<m;i++)
       {
           for(int j =1; j<n;j++)
           {
              if(t[i-1]==s[j-1])
              {
                  dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
              }
              else 
              dp[i][j]=dp[i][j-1];
           }
       }
       return dp[m-1][n-1];

}


int main(int argc, char **argv)
{
        string s1 ="xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string s2 = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaehey";
     cout<<numDistinct(s1,s2)<<endl;
    return 0;
}