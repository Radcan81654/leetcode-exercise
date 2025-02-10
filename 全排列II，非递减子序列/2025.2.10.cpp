//https://leetcode.cn/problems/non-decreasing-subsequences/submissions/598316329/
class Solution {
public:
    vector<int> path;
    set<vector<int>> result;
    void backtrack(vector<int>& nums, int index)
    {
        if (path.size() > 1)
            result.insert(path);
        for (int i = index; i < nums.size(); i++)
        {
            if (path.size() == 0 || nums[i] >= path[path.size() - 1])
            {
                path.push_back(nums[i]);
                backtrack(nums, i + 1);
                path.pop_back();
            }

        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        vector<vector<int>> ret;
        for (auto i : result)
            ret.push_back(i);
        return ret;


    }
};


//https://leetcode.cn/problems/permutations-ii/submissions/598317081/
class Solution {
public:
    vector<int> path;
    set<vector<int>> result;
    vector<int> judge;
    void backtrack(vector<int>& nums)
    {
        if (nums.size() == path.size())
        {
            result.insert(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (judge[i] == 0)
            {
                path.push_back(nums[i]);
                judge[i] = 1;
                backtrack(nums);
                path.pop_back();
                judge[i] = 0;
            }

        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        judge.resize(nums.size());
        backtrack(nums);
        vector<vector<int>> ret;
        for (auto i : result)
        {
            ret.push_back(i);
        }
        return ret;



    }
};