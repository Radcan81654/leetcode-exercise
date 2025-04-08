//https://leetcode.cn/problems/house-robber/submissions/620129691/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if (nums.size() >= 2)
            dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];


    }
};


//https://leetcode.cn/problems/house-robber-ii/submissions/620155457/
class Solution {
public:
    int my_rob(vector<int>& nums, int begin, int end)
    {
        vector<int> dp(nums.size(), 0);
        dp[begin] = nums[begin];
        dp[begin + 1] = max(nums[begin], nums[begin + 1]);
        for (int i = begin + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];

    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[1], nums[0]);
        int ret1 = my_rob(nums, 0, nums.size() - 2);
        int ret2 = my_rob(nums, 1, nums.size() - 1);
        return max(ret1, ret2);

    }
};