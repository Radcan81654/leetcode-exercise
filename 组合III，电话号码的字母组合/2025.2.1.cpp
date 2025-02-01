https://leetcode.cn/problems/combination-sum-iii/description/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    vector<int> judge;
    void backtrack(int n, int index, int k)
    {
        int sum = 0;
        for (int i = 0; i < path.size(); i++)
        {
            sum += path[i];
        }
        if (sum == n && path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i <= 9 && judge[i - 1] == 0; i++)
        {

            path.push_back(i);
            judge[i - 1] = 1;
            backtrack(n, index + 1, k);
            path.pop_back();
            judge[i - 1] = 0;
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        judge.resize(9);
        backtrack(n, 1, k);
        return result;

    }
};

//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/596189647/
class Solution {
public:
    string path;
    vector<string> result;
    vector<string> vs = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

    void backtrack(string digits, int index)
    {

        if (path.size() == digits.size())
        {
            result.push_back(path);
            return;
        }
        int vs_index = digits[index] - '0';
        string tmp = vs[vs_index];
        for (int i = 0; i < tmp.size(); i++)
        {
            path.push_back(tmp[i]);
            backtrack(digits, index + 1);
            path.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.size())
            return result;
        backtrack(digits, 0);
        return result;

    }
};