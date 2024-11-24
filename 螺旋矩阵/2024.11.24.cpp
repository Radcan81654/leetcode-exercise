//ÂÝÐý¾ØÕó
//https://leetcode.cn/problems/spiral-matrix-ii/submissions/582794339/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, up = 0;
        int right = n - 1, down = n - 1;
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int cur = 1;
        while (cur <= n * n)
        {
            for (int i = left; i <= right; i++)
                ret[up][i] = cur++;
            up++;
            for (int i = up; i <= down; i++)
                ret[i][right] = cur++;
            right--;
            for (int i = right; i >= left; i--)
                ret[down][i] = cur++;
            down--;
            for (int i = down; i >= up; i--)
                ret[i][left] = cur++;
            left++;

        }
        return ret;

    }
};