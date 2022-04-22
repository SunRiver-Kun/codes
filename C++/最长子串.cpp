class Solution {
  public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        int maxLenth = 0;//记录最长公共子串的长度
        //记录最长公共子串最后一个元素在字符串str1中的位置
        int maxLastIndex = 0;
        int *dp = new int[str2.length() + 1];
        for (int i = 0; i < str1.length(); i++) {
            //注意这里是倒叙
            for (int j = str2.length() - 1; j >= 0; j--) {
                //递推公式，两个字符相等的情况
                if (str1[i] == str2[j]) {
                    dp[j + 1] = dp[j] + 1;
                    //如果遇到了更长的子串，要更新，记录最长子串的长度，
                    //以及最长子串最后一个元素的位置
                    if (dp[j + 1] > maxLenth) {
                        maxLenth = dp[j + 1];
                        maxLastIndex = i;
                    }
                } else {
                    //递推公式，两个字符不相等的情况
                    dp[j + 1] = 0;
                }
            }
        }
        //最字符串进行截取，substring(a,b)中a和b分别表示截取的开始和结束位置
        return str1.substr(maxLastIndex - maxLenth + 1, maxLenth);
    }

};