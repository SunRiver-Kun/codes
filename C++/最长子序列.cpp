#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <class _Func>
int MaxSubLength(vector<int>& h, _Func&& fn){
    vector<int> dp(h.size(), 1);
    for(int i=1; i<h.size(); ++i){
        int maxdp = 0;
        for(int j=0; j<i; ++j){
            if(fn(h[j], h[i]))
                maxdp = max(maxdp, dp[j]);
        }
        dp[i] = maxdp + 1;
    }
    return *max_element(begin(dp), end(dp));
}

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; ++i) { cin >> h[i]; }
    //最长下降子序列
    cout << MaxSubLength(h, greater_equal<int>()) << endl;
    //最长严格上升子序列等于最少下降子序列数
    cout << MaxSubLength(h, less<int>()) << endl;
}