//二叉树的迭代遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if (!root)
            return ret;
        TreeNode* cur = root;
        while (cur)
        {
            while (cur)
            {
                st.push(cur);
                ret.push_back(cur->val);
                cur = cur->left;
            }
            while (!st.empty())
            {
                TreeNode* top = st.top();
                if (top->right != nullptr)
                {
                    cur = top->right;
                    st.pop();
                    break;
                }
                st.pop();
            }
        }
        return ret;

    }
};
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
        if (!root)
            return ret;
        TreeNode* cur = root;
        while (cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            while (!st.empty())
            {
                TreeNode* top = st.top();
                ret.push_back(top->val);
                if (top->right != nullptr)
                {
                    cur = top->right;
                    st.pop();
                    break;
                }
                st.pop();
            }
        }
        return ret;

    }


};
//https://leetcode.cn/problems/binary-tree-postorder-traversal/submissions/587063913/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if (!root)
            return ret;
        TreeNode* cur = root;
        while (cur)
        {
            while (cur)
            {
                st.push(cur);
                ret.push_back(cur->val);
                cur = cur->right;
            }
            while (!st.empty())
            {
                TreeNode* top = st.top();
                if (top->left != nullptr)
                {
                    cur = top->left;
                    st.pop();
                    break;
                }
                st.pop();
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;

    }
};
