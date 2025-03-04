//https://leetcode.cn/problems/integer-break/description/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
            }
        }
        return dp[n];




    }
};

//https://leetcode.cn/problems/unique-binary-search-trees/description/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
                dp[i] += dp[i - j] * dp[j - 1];
        }
        return dp[n];
    }
};

