class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        //dp[i][j] 表示以s1中以s1[i-1]结尾，s2中以s2[j-1]结尾的最长公共子序列的最大长度
        //子序列不等于子串，子序列不要求连续，只要求相对位置（前后）不变
        //当s1[i]==s2[j]时它们可以加入最长子序列中， dp[i][j] = max(dp[i][j],1 + dp[i-1][j-1])
        //当s1[i]!=s2[j]时，dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]))
        vector<vector<int> > dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        for(int i=0; i<s1.length(); ++i){
            for(int j=0; j<s2.length(); ++j){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1], 1 + dp[i][j]);
                }
                else{
                    dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i][j+1], dp[i+1][j]));
                }
            }
        }
        string result;
        for(int i=dp.size()-1, j=dp.front().size()-1; dp[i][j]>0;){
            if(s1[i-1] == s2[j-1]){
                result += s1[i-1];
                --i;
                --j;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                --i;
            }
            else{
                --j;
            }
        }
        reverse(begin(result), end(result));
        return result.empty() ? "-1" : result ; 
    }
};