//¶þ²æÊ÷µÄµÝ¹é±éÀú
//https://leetcode.cn/problems/binary-tree-preorder-traversal/
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
    vector<int> ret;
    void preorder(TreeNode* root)
    {
        if (!root)
            return;
        ret.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ret;
    }
};
//https://leetcode.cn/problems/binary-tree-inorder-traversal/
/**
*Definition for a binary tree node.
* struct TreeNode {
    *int val;
    *TreeNode* left;
    *TreeNode* right;
    *TreeNode() : val(0), left(nullptr), right(nullptr) {}
    *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    *TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    *
};
*/
class Solution {
public:
    vector<int> ret;
    void preorder(TreeNode* root)
    {
        if (!root)
            return;
        preorder(root->left);
        ret.push_back(root->val);
        preorder(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        preorder(root);
        return ret;

    }
};
//https://leetcode.cn/problems/binary-tree-postorder-traversal/submissions/587056129/
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
    vector<int> ret;
    void postorder(TreeNode* root)
    {
        if (!root)
            return;
        postorder(root->left);
        postorder(root->right);
        ret.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ret;

    }
};