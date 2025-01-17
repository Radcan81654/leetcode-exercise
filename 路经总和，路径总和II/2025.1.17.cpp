//https://leetcode.cn/problems/path-sum/description/
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
    bool my_hasPathSum(TreeNode* root, int targetSum, int currentSum)
    {
        if (!root)
            return false;
        int newCurrentSum = currentSum + root->val;
        //��ֹ·��û����ʹﵽtargetSum
        if (newCurrentSum == targetSum && !root->left && !root->right)
            return true;
        return my_hasPathSum(root->left, targetSum, newCurrentSum) || my_hasPathSum(root->right, targetSum, newCurrentSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return my_hasPathSum(root, targetSum, 0);

    }
};

//https://leetcode.cn/problems/path-sum-ii/description/
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
private:
    vector<vector<int>> result;
    vector<int> path;
    // �ݹ麯������Ҫ����ֵ����Ϊ����Ҫ����������
    void traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) { // ������Ҷ�ӽڵ����ҵ��˺�Ϊsum��·��
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return; // ����Ҷ�ӽڵ��û���ҵ����ʵıߣ�ֱ�ӷ���

        if (cur->left) { // �� ���սڵ㲻������
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);    // �ݹ�
            count += cur->left->val;        // ����
            path.pop_back();                // ����
        }
        if (cur->right) { // �� ���սڵ㲻������
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);   // �ݹ�
            count += cur->right->val;       // ����
            path.pop_back();                // ����
        }
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if (root == NULL) return result;
        path.push_back(root->val); // �Ѹ��ڵ�Ž�·��
        traversal(root, sum - root->val);
        return result;
    }
};