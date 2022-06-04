class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int rob(vector<int>& nums) {
        // write code here
        vector<int> dp(nums.size()+1);
        //偷第一家，不能偷最后一家
        dp[1] = nums[0];
        for(int i=2; i<nums.size(); ++i){
            dp[i] = max(nums[i-1]+dp[i-2], dp[i-1]);
        }
        int res = dp[nums.size()-1];
        //不偷第一家
        dp[1] = 0;
        for(int i=2; i<=nums.size(); ++i){
            dp[i] = max(nums[i-1]+dp[i-2], dp[i-1]);
        }
        return max(res, dp[nums.size()]);
    }
};