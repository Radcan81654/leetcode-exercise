//https://leetcode.cn/problems/last-stone-weight-ii/description/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++)
            sum += stones[i];
        int target = sum / 2;
        vector<int> dp(1501);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
        return sum - dp[target] * 2;

    }
};