//¶þ²æÊ÷ÖÐÐò±éÀú
//https://leetcode.cn/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        while (root || (!st.empty()))
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            TreeNode* top = st.top();
            ret.push_back(top->val);
            st.pop();
            if (top->right != nullptr)
            {
                root = top->right;
            }

        }
        return ret;
    }
};