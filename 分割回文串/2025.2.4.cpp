//https://leetcode.cn/problems/palindrome-partitioning/submissions/596742668/
class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;
    bool is_ok(string s, int start, int end)
    {

        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    void backtrack(string s, int index)
    {
        if (index >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (is_ok(s, index, i) == true)
            {
                string tmp = s.substr(index, i - index + 1);
                path.push_back(tmp);

            }
            else
                continue;
            backtrack(s, i + 1);
            path.pop_back();
        }

    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;

    }
};