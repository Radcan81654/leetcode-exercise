//https://leetcode.cn/problems/find-mode-in-binary-search-tree/
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
    unordered_map<int, int> umap;
    void travelsal(TreeNode* root)
    {
        if (!root)
            return;
        umap[root->val]++;
        travelsal(root->left);
        travelsal(root->right);
        return;

    }
    vector<int> findMode(TreeNode* root) {
        travelsal(root);
        vector<int> ret;
        int count = 0;
        for (auto i : umap)
        {
            if (i.second > count)
                count = i.second;
        }
        for (auto i : umap)
        {
            if (i.second == count)
                ret.push_back(i.first);
        }
        return ret;

    }
};


//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/594756790/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* travelsal(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return root;
        if (p->val < root->val && q->val < root->val)
        {
            return travelsal(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val)
        {
            return travelsal(root->right, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return travelsal(root, p, q);
    }
};