//https://leetcode.cn/problems/combination-sum/description/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtrack(vector<int>& candidates, int target, int sum, int index)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum + candidates[i], i);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (!candidates.size())
            return result;
        //sort(candidates.begin(),candidates.end());
        backtrack(candidates, target, 0, 0);
        return result;
    }
};
//https://leetcode.cn/problems/combination-sum-ii/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    vector<int> judge;
    void backtrack(vector<int>& candidates, int target, int sum, int index)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && judge[i] == 0; i++)
        {
            //// 要对同一树层使用过的元素进行跳过,否则result中出现多个相同的path
            if (i > 0 && candidates[i] == candidates[i - 1] && judge[i - 1] == 0) {
                continue;
            }
            path.push_back(candidates[i]);
            judge[i] = 1;
            backtrack(candidates, target, sum + candidates[i], i + 1);
            judge[i] = 0;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        judge.resize(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return result;

    }
};