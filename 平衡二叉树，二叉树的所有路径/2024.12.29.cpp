//二叉树的所有路径
//https://leetcode.cn/problems/binary-tree-paths/description/
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
    vector<string> ret;
    void my_binaryTreePaths(TreeNode* root, string tmp)
    {
        if (!root)
            return;
        if (!tmp.empty())
            tmp += "->";
        tmp += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(tmp);
            return;
        }
        my_binaryTreePaths(root->left, tmp);
        my_binaryTreePaths(root->right, tmp);
        return;



    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp;
        my_binaryTreePaths(root, tmp);
        return ret;


    }
};








//平衡二叉树
//https://leetcode.cn/problems/balanced-binary-tree/submissions/590016591/

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
    int getHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};