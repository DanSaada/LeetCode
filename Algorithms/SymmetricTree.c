/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
 
Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100*/

#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool recIsSymmetric(struct TreeNode* n1, struct TreeNode* n2) {
    if (n1 == NULL && n2 == NULL) {return true;}

    if (n1 && n2) {
        return n1->val == n2->val && 
               recIsSymmetric(n1->left, n2->right) && 
               recIsSymmetric(n1->right, n2->left);
    }

    return false;
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {return true;}

    return recIsSymmetric(root->left, root->right);
}