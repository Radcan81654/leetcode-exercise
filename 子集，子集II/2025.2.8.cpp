//https://leetcode.cn/problems/subsets/submissions/597793383/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, int index)
    {

        result.push_back(path);
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;



    }
};

//https://leetcode.cn/problems/subsets-ii/submissions/597793431/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    vector<int> judge;
    void backtrack(vector<int>& nums, int index)
    {

        result.push_back(path);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && judge[i - 1] == 0)
                continue;
            path.push_back(nums[i]);
            judge[i] = 1;
            backtrack(nums, i + 1);
            path.pop_back();
            judge[i] = 0;
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        judge.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;

    }
};