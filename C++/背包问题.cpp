/*  01背包
描述
你有一个背包，最多能容纳的体积是V。
（1）求这个背包至多能装多大价值的物品？
（2）若背包恰好装满，求至多能装多大价值的物品？

https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc?tpId=308&tqId=2032575&ru=/exam/oj&qru=/ta/algorithm-start/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D308
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, V;
    cin >> n >> V;
    int* v = new int[n];
    int* w = new int[n];
    vector<int> dp(V+1, 0);
    for(int i=0; i<n; ++i){
        cin >> v[i] >> w[i];
    }
    for(int i=0; i<n; ++i){
        for(int j=V; j>=v[i]; --j){
            dp[j] = max( dp[j] ,dp[j-v[i]] + w[i] );
        }
    }
    cout << dp[V] << endl;
    
    fill(begin(dp),end(dp),-9999999);
    dp[0] = 0;
    for(int i=0; i<n; ++i){
        for(int j=V; j>=v[i]; --j){
            dp[j] = max( dp[j] ,dp[j-v[i]] + w[i] );
        }
    }
    cout << max(0, dp[V]) << endl;
}