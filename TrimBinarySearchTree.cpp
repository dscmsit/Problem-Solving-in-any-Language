class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->val >=low && root->val<=high)
        {
            root->right=trimBST(root->right,low,high);
            root->left=trimBST(root->left,low,high);
        }
        else if(root->val <low)
        {
            return trimBST(root->right,low,high);
        }
        else 
        {
            return trimBST(root->left,low,high);
        }
        return root;
    }
};
