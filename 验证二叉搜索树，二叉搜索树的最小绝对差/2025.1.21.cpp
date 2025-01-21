//https://leetcode.cn/problems/validate-binary-search-tree/description/
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
    bool my_isValidBST(TreeNode* root, long long min_val, long long max_val) {
        if (!root)
            return true;
        //当前树（由于他也是父树的子树）的数值限制    
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return my_isValidBST(root->left, min_val, root->val) && my_isValidBST(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return my_isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

//https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
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
    vector<int> content;
    void travelsal(TreeNode* root)
    {
        if (!root)
            return;
        travelsal(root->left);
        content.push_back(root->val);
        travelsal(root->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        travelsal(root);
        int ret = INT_MAX;
        for (int i = 1; i < content.size(); i++)
        {
            ret = min(ret, content[i] - content[i - 1]);
        }
        return ret;
    }
};