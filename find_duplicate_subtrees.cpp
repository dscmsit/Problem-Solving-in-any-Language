class Solution
{
public:
#define right root->right
#define left root->left
    map<string, pair<int, TreeNode *>> m;

    string help(TreeNode *root)
    {
        if (!root)
        {
            return "$";
        }

        string s = to_string(root->val) + "," + help(left) + "," + help(right);

        m[s].second = root;
        m[s].first++;

        return s;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> v;
        help(root);
        for (auto it = m.begin(); it != m.end(); it++)
        {

            if (it->second.first > 1)
            {

                TreeNode *temp = it->second.second;
                v.push_back(temp);
            }
        }

        return v;
    }
};