//https://leetcode.cn/problems/permutations/description/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    vector<int> used;
    void backtrack(vector<int>& nums, int index)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 1)
                continue;
            path.push_back(nums[i]);
            used[i] = 1;
            backtrack(nums, index + 1);
            used[i] = 0;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size());
        //注意112的全排列只有3个
        backtrack(nums, 0);
        return result;


    }
};