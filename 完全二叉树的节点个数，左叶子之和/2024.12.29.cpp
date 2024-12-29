//完全二叉树的节点个数
//https://leetcode.cn/problems/count-complete-tree-nodes/description/
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
    int count;
    int countNodes(TreeNode* root) {
        if (!root)
            return count;
        count++;
        countNodes(root->left);
        countNodes(root->right);
        return count;


    }
};

//左叶子之和
//https://leetcode.cn/problems/sum-of-left-leaves/description/
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
    int sum;
    int my_sumOfLeftLeaves(TreeNode* root, string s)
    {
        if (!root)
            return sum;
        if (root->left == nullptr && root->right == nullptr && s == "left")
        {
            sum += root->val;
        }
        my_sumOfLeftLeaves(root->left, "left");
        my_sumOfLeftLeaves(root->right, "right");
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return my_sumOfLeftLeaves(root, "s");


    }
};