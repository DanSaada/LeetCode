/*Given a binary tree, determine if it is height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true
 
Constraints:
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <math.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int recIsBalanced(struct TreeNode* root) {
    if (root == NULL) {return 0;}
    int leftHeight = recIsBalanced(root->left);
    int rightHeight = recIsBalanced(root->right);

    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {return true;}

    int heightDiff = recIsBalanced(root);

    return heightDiff != -1;
}