#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size(); 
    
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0; i<=n; ++i) { dp[i][0] = i; }
    for(int i=0; i<=m; ++i) { dp[0][i] = i; }
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int op1 = 1 + dp[i][j+1];  //增or删str1
            int op2 = 1 + dp[i+1][j];  //增or删str2
            int op3 = s1[i]==s2[j] ? dp[i][j] : dp[i][j]+1; //替换str1
            dp[i+1][j+1] = min(min(op1, op2), op3);
        }
    }
    cout << dp[n][m];
}