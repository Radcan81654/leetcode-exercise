//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        vector<int> arr;
        for (int i = 0; i < prices.size(); i++)
        {
            if (arr.size() == 0 || prices[i] >= arr[arr.size() - 1])
                arr.push_back(prices[i]);
            else
            {
                ret += arr[arr.size() - 1] - arr[0];
                arr.clear();
                arr.push_back(prices[i]);
            }

        }
        if (arr.size())
            ret += arr[arr.size() - 1] - arr[0];
        return ret;

    }
};
//Õý½â£º
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};
https://leetcode.cn/problems/jump-game/description/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(cover, i + nums[i]);
            if (i >= nums.size() - 1)
                return true;
        }
        return false;
    }
};