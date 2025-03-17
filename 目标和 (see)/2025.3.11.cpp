//https://leetcode.cn/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (abs(target) > sum)
            return 0; // 没有方案
        if ((target + sum) % 2 == 1)
            return 0; // 没有方案
        int bagSize = (target + sum) / 2;

        //在放置[0,i]这个闭区间里的元素的时候，它们的和恰好是j时，有dp[i][j]种放置方法
        vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));

        // 初始化最上行
        if (nums[0] <= bagSize)
            dp[0][nums[0]] = 1;

        // 初始化最左列，最左列其他数值在递推公式中就完成了赋值
        dp[0][0] = 1;

        int numZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) numZero++;
            dp[i][0] = (int)pow(2.0, numZero);
        }

        // 以下遍历顺序行列可以颠倒
        for (int i = 1; i < nums.size(); i++) { // 行，遍历物品
            for (int j = 0; j <= bagSize; j++) { // 列，遍历背包
                if (nums[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                //当前的这个情况取决于“不用放nums[i]”的情况，加上"用放nums[i]"的情况的数量
            }
        }
        return dp[nums.size() - 1][bagSize];
    }
};