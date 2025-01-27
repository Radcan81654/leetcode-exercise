//https://leetcode.cn/problems/insert-into-a-binary-search-tree/submissions/595579753/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* precur = nullptr;
        TreeNode* cur = root;
        TreeNode* newnode = new TreeNode(val);
        if (!cur)
            return newnode;
        while (cur)
        {
            if (val < cur->val)
            {
                precur = cur;
                cur = cur->left;
            }
            else
            {
                precur = cur;
                cur = cur->right;
            }
        }
        val < precur->val ? (precur->left = newnode) : (precur->right = newnode);
        return root;

    }
};

//https://leetcode.cn/problems/delete-node-in-a-bst/submissions/595656886/
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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;

        if (root->val == key)
        {
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            else if (!root->left)
            {
                auto retNode = root->right;
                delete root;
                return retNode;
            }
            else if (!root->right)
            {
                auto retNode = root->left;
                delete root;
                return retNode;
            }
            else
            {
                TreeNode* cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        return root;


    }
};