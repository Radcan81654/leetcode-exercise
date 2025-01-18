//最大二叉树
//https://leetcode.cn/problems/maximum-binary-tree/description/
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
    TreeNode* construct(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int v = left;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] > nums[v])
                v = i;
        }
        TreeNode* ret = new TreeNode(nums[v]);
        ret->left = construct(nums, left, v - 1);
        ret->right = construct(nums, v + 1, right);
        return ret;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);

    }
};

//合并二叉树
//https://leetcode.cn/problems/merge-two-binary-trees/description/
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* ret = new TreeNode(0);
        if (!root1 && !root2)
            return nullptr;
        else if (root1 && !root2)
        {
            return root1;
        }
        else if (!root1 && root2)
        {
            ret->val = root2->val;
            return root2;
        }
        ret->val = root1->val + root2->val;
        ret->left = mergeTrees(root1->left, root2->left);
        ret->right = mergeTrees(root1->right, root2->right);
        return ret;


    }
};