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
    TreeNode* pruneTree(TreeNode* root) {
       if(root->left==NULL&&root->right==NULL)
       {
           if(root->val==1)
           {
               return root;
           }
           else
           {
               return NULL;
           }
       }
        TreeNode*a=NULL;
        TreeNode*b=NULL;
     if(root->left)
     {
         a=pruneTree(root->left);
     }
        if(root->right)
        {
          b=pruneTree(root->right);
        }
        
        if(a==NULL&&b==NULL)
        {
         
               root->left=NULL;
               root->right=NULL;
                       if(root->val==1)
           {
               return root;
           }
           else
           {
               return NULL;
           }
        }
       else if(a!=NULL&&b!=NULL)
        {
      
            return root;
        }
        else if(a!=NULL&&b==NULL)
        {
               root->right=NULL;
               return root;
        }
         else 
        {
              root->left=NULL;
              return root;
        }
      
    }
};