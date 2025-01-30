https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/submissions/595965295/
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
     TreeNode* travelsal(vector<int>& nums, int start, int end)
     {
         if (start<0 || end>nums.size() - 1 || start > end)
             return nullptr;
         int index = (start + end) / 2;
         TreeNode* ret = new TreeNode(nums[index]);
         ret->left = travelsal(nums, start, index - 1);
         ret->right = travelsal(nums, index + 1, end);
         return ret;
     }
     TreeNode* sortedArrayToBST(vector<int>& nums) {
         TreeNode* ret = travelsal(nums, 0, nums.size() - 1);
         return ret;

     }
 };

 //https://leetcode.cn/problems/trim-a-binary-search-tree/submissions/595970269/
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
     TreeNode* trimBST(TreeNode* root, int low, int high) {
         if (root == nullptr) return nullptr;
         if (root->val < low) {
             TreeNode* right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
             return right;
         }
         if (root->val > high) {
             TreeNode* left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
             return left;
         }
         root->left = trimBST(root->left, low, high); // root->left接入符合条件的左孩子
         root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
         return root;
     }
 };