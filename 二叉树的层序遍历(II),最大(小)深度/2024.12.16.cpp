//�������Ĳ������
//https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();//ÿһ���size
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
//�������Ĳ������II
//https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            vector<int> tmp;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);


            }
            ret.push_back(tmp);
        }
        reverse(ret.begin(), ret.end());
        return ret;

    }
};
//������������ͼ
//https://leetcode.cn/problems/binary-tree-right-side-view/description/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> level_order;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            vector<int> tmp;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                tmp.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            level_order.push_back(tmp);
        }
        vector<int> ret;
        for (int i = 0; i < level_order.size(); i++)
        {
            ret.push_back(level_order[i].back());
        }
        return ret;




    }
};
//��������������
//https://leetcode.cn/problems/maximum-depth-of-binary-tree/submissions/587379058/
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // ���ӽڵ����
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }

        return depth;

    }
};
//����������С���
//https://leetcode.cn/problems/minimum-depth-of-binary-tree/submissions/587379230/
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // �����Ҷ�ӽڵ㣬���ص�ǰ���
                if (node->left == NULL && node->right == NULL) {
                    return depth;
                }

                // ���ӽڵ����
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }

        return depth;
    }
};