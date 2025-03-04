//https://leetcode.cn/problems/unique-paths/description/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m][n];

    }
};

//https://leetcode.cn/problems/unique-paths-ii/description/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i + 1][j + 1] = INT_MIN;
            }
        }
        dp[0][1] = 1;
        for (int i = 1; i < obstacleGrid.size() + 1; i++)
        {
            for (int j = 1; j < obstacleGrid[0].size() + 1; j++)
            {
                if (dp[i][j] == INT_MIN)
                    continue;
                int sum1 = dp[i - 1][j] == INT_MIN ? 0 : dp[i - 1][j];
                int sum2 = dp[i][j - 1] == INT_MIN ? 0 : dp[i][j - 1];
                dp[i][j] = sum1 + sum2;
            }
        }
        return max(dp[obstacleGrid.size()][obstacleGrid[0].size()], 0);


    }
};
