

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;

class balancedBinaryTree{
  
    public int check_balance(TreeNode root){
        if(root == null){
            return 0;
        }
        int lh = check_balance(root.left);
        int rh = check_balance(root.right);
        if(lh == -1 || rh == -1){
            return -1;
        }
        if(Math.abs(lh - rh) > 1){
            return -1;
        }
        return Math.max(lh,rh) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        if(check_balance(root) == -1){
            return false;
        }
        return true;
    }
    public static void main(String[]args){
//       Example
      Scanner sc = new Scanner(System.in);
      TreeNode root = new TreeNode(sc.nextInt());
      root.left = new TreeNode(sc.nextInt());
      root.right = new TreeNode(sc.nextInt());
      System.out.println(isBalanced(root));
    }
}
