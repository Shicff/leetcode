/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int>> ret;
        
        if(!root) return ret;
        
        queue<TreeNode*> que;
        que.push(root);
              
        while(!que.empty()){
            int q = que.size();
            vector<int> tmp; 
            
            while(q){
                tmp.push_back(que.front() -> val);
                if(que.front() -> left)
                    que.push(que.front() -> left);
                if(que.front() -> right)
                    que.push(que.front() -> right);
                que.pop();
                q--;
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};