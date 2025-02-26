//https://leetcode.cn/problems/assign-cookies/submissions/603298299/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ret = 0;
        for (int gi = 0, si = 0; gi < g.size() && si < s.size();)
        {
            if (s[si] >= g[gi])
            {
                ret++;
                gi++;
                si++;
            }
            else
            {
                si++;
            }

        }
        return ret;

    }
};

https://leetcode.cn/problems/wiggle-subsequence/submissions/603312180/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 1;
        int pregap = 0;
        int curgap = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curgap = nums[i + 1] - nums[i];
            if (pregap >= 0 && curgap < 0 || (pregap <= 0 && curgap > 0))
            {
                result++;
                pregap = curgap;
            }
        }
        return result;
    }
};