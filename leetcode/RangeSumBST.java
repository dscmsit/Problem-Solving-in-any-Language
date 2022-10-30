class RangeSumBST {
    int sum=0;
    public int rangeSumBST(TreeNode root, int low, int high) {
        bfs(root,low,high);
        return sum;
    }
    
    public void bfs(TreeNode root,int low, int high)
    {
        if (root==null) return;
        if (low<=root.val && root.val<=high) sum+=root.val;
        
        bfs(root.left,low,high);
        bfs(root.right,low,high);
    }
}