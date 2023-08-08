#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    intmax_t* arr = new intmax_t[n+1];
    intmax_t* dp = new intmax_t[n+2]{};
    
    for(int i=1; i<=n; ++i) { cin >> arr[i]; }
    
    for(int i=0,l,r,k; i<m; ++i){
        cin >> l >> r >>k;
        dp[l] += k;
        dp[r+1] -= k;
    }
    for(int i=1; i<=n; ++i) {  
        dp[i] += dp[i-1];
        cout << arr[i] + dp[i] << ' ';   
    }
}