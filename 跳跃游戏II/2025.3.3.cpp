//https://leetcode.cn/problems/jump-game-ii/submissions/605609733/
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int curDistance = 0;
        int nextDistance = 0;
        int count = 0;
        for (int i = 0; i <= curDistance; i++)
        {
            nextDistance = max(nextDistance, i + nums[i]);
            if (i == curDistance)
            {
                count++;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1)
                    break;
            }

        }
        return count;
    }
};