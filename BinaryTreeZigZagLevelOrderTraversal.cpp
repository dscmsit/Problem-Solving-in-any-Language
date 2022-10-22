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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // Method-1 (Using Queue)
        if (!root)
        {
            return {};
        }
        vector<vector<int>> res;

        queue<TreeNode *> q;
        q.push(root);

        int x = 0;
        while (!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            if (x % 2 == 0)
            {
                res.push_back(temp);
                x++;
            }
            else
            {
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
                x++;
            }
        }
        return res;

        // Method-2(Using stack)
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return {};
        }
        stack<TreeNode *> p;
        stack<TreeNode *> q;
        p.push(root);
        while (p.size() != 0 || q.size() != 0)
        {
            vector<int> v;
            while (p.size() != 0)
            {
                TreeNode *curr = p.top();
                v.push_back(curr->val);
                p.pop();
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
            if (!v.empty())
            {
                ans.push_back(v);
            }
            vector<int> t;
            while (q.size() != 0)
            {
                TreeNode *curr = q.top();
                t.push_back(curr->val);
                q.pop();
                if (curr->right != NULL)
                {
                    p.push(curr->right);
                }
                if (curr->left != NULL)
                {
                    p.push(curr->left);
                }
            }
            if (!t.empty())
            {
                ans.push_back(t);
            }
        }
        return ans;
    }
};