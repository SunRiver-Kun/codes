#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n, V;
    cin >> n >> V;
    int* v = new int[n];
    int* w = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> w[i];
    }
    int* dp = new int[V+1]{};
    for(int i=0; i<n; ++i){
        for(int j=v[i]; j<=V; ++j){
            dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    
    memset(dp, 0x80, sizeof(int[V+1]));	//较小值
    dp[0] = 0;
    for(int i=0; i<n; ++i){
        for(int j=v[i]; j<=V; ++j){
            dp[j] = max(dp[j], dp[j-v[i]] + w[i]);
        }
    }
    cout << max(dp[V],0) << endl;
    
}