//https://leetcode.cn/problems/min-cost-climbing-stairs/description/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);//走完楼梯的费用
        dp[2] = min(cost[1], cost[0]);
        for (int i = 3; i < cost.size() + 1; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[dp.size() - 1];


    }
};