//https://leetcode.cn/problems/house-robber-iii/submissions/620401747/
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
 //����������Ŀ����ȷ��������ʽ
class Solution {
public:
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        if (umap.count(root))//��ѯroot���key�ĳ��ִ���(1/0)
            return umap[root];
        int value1 = root->val;
        if (root->left)
        {
            value1 += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right)
        {
            value1 += (rob(root->right->left) + rob(root->right->right));
        }

        int value2 = rob(root->right) + rob(root->left);
        umap[root] = max(value1, value2);
        return umap[root];


    }
};