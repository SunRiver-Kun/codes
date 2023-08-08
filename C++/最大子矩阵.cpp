#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin >> dp[i][j];
            dp[i][j] += dp[i][j-1];
        }
    }
    
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            dp[i][j] += dp[i-1][j];
        }
    }
    
    int maxdp = INT32_MIN;
    for(int x1=1; x1<=N; ++x1){
        for(int y1=1; y1<=N; ++y1){
            for(int x2=x1; x2<=N; ++x2){
                for(int y2=y1; y2<=N; ++y2){
                    maxdp = max(maxdp, dp[x1-1][y1-1]+dp[x2][y2]
                                -dp[x1-1][y2]-dp[x2][y1-1]);
                }
            }
        }
    }
    cout << maxdp;
}