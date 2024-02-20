/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {    
        if(root == null) return null;
        if(root == p || root == q) return root;

        // Post-order traversal
        TreeNode left = lowestCommonAncestor(root.left, p, q);       
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // p and q were found in different subtrees with the current root as their common ancestor. 
        if(left != null && right != null) return root;

        // both p and q are located in the same subtree
        return left == null? right: left;
    }
}

