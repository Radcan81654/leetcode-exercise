//https://leetcode.cn/problems/convert-bst-to-greater-tree/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void travelsal(TreeNode* cur, int& pre)
    {
        if (!cur)
            return;
        travelsal(cur->right, pre);
        cur->val += pre;
        pre = cur->val;
        travelsal(cur->left, pre);
        return;

    }
    TreeNode* convertBST(TreeNode* root) {
        int pre = 0;
        travelsal(root, pre);
        return root;



    }
};

//https://leetcode.cn/problems/combinations/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtrack(int end, int index, int k)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i <= end; i++)
        {
            if (path.size() == 0 || i > path[path.size() - 1])//减去多余情况
            {
                path.push_back(i);
                backtrack(end, index + 1, k);
                path.pop_back();
            }


        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        int index = 1;
        backtrack(n, 1, k);
        return result;
    }
};