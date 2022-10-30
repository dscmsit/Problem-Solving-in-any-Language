class MergeTwoBinaryTrees {
    //TreeNode merge = new TreeNode();
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1==null) return root2;
        if (root2==null) return root1;
        if (root1==null && root2==null) return root1;
        
        bfs(root1,root2);
        return root1;
    }
    public void bfs(TreeNode root1, TreeNode root2)
    {
        if (root1==null || root2==null) return;
        if (root2.left!=null && root1.left==null) root1.left= root2.left;
        if (root2.right!=null && root1.right==null) root1.right = root2.right;
        if (root1!=null && root2!=root1) root1.val = root1.val + root2.val;
        
        bfs(root1.left,root2.left);
        bfs(root1.right,root2.right);
    }
}