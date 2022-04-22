class Solution {
public:
    int minMoney(vector<int>& arr, int aim) {
        int dp[aim + 5];    //dp[i]表示给i需要给多少张money
        dp[0] = 0;
        for (int i = 1; i <= aim; ++i) dp[i] = 1e9;
        for (int i = 0; i < (int)arr.size(); ++i) {
            for (int j = arr[i]; j <= aim; ++j) dp[j] = min(dp[j], dp[j - arr[i]] + 1); //dp[arrp[i]] = 1   其他可能不变（未知）或变小等
        }
        if (dp[aim] == 1e9) return -1;
        return dp[aim];
    }
};


class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    
    int minMoney(vector<int>& arr, int aim) {
        // write code here
        if(aim < 0 || arr.empty()) { return -1; }
        else if(aim == 0) { return 0; }
        
        sort(begin(arr), end(arr));
        first = begin(arr);
        last = end(arr);
        counts = make_unique<size_t[]>(aim + 1);
        for(auto& v : arr){
            counts[v] = 1;
        }
        return GetMinMoney(aim);
    }
    
private:
    //0未知 UINT_MAX不可达  其他最小
    size_t GetMinMoney(int aim){
        if(aim < 0) { return UINT_MAX; }
        else if(aim == 0) { return 0; }
        else if(counts[aim]) { return counts[aim]; }
        
        size_t submin = UINT_MAX;
        auto end = upper_bound(first, last, aim);
        for(auto it = first; it!=end; ++it){
            submin = min(submin, GetMinMoney(aim - *it));
        }
        counts[aim] = submin==UINT_MAX ? UINT_MAX : 1 +submin;
        return counts[aim];
    }
    
    unique_ptr<size_t[]> counts;
    vector<int>::iterator first, last; 
};