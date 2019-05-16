/*
给定一个二叉树，检查它是否是镜像对称的。
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root, root);
    }
    
    bool ismirror(TreeNode* p, TreeNode *q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p -> val == q -> val)
            return ismirror(p -> left, q ->right) && ismirror(p -> right, q -> left);
        return false;
    }
    
};