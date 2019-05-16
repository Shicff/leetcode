/**

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]


入队，如例：q.push(x); 将x接到队列的末端。

出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。

访问队首元素，如例：q.front()，即最早被压入队列的元素。

访问队尾元素，如例：q.back()，即最后被压入队列的元素。

判断队列空，如例：q.empty()，当队列空时，返回true。

访问队列中的元素个数，如例：q.size()
*/
/*
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL) return result; //空
        
        int cur; 
        int next=1; 
        
        TreeNode* c=root;  //新指针
        
        queue<TreeNode*> q; //放进队列
        q.push(c);
        
        while(!q.empty())
        { 
            cur=next; 
            next=0; 
            
            vector<int> temp; 
            while(cur>0){
                c=q.front(); //最早进入的元素
                q.pop(); 
                cur--;
                
                temp.push_back(c->val); 
                if(c->left!=NULL) { 
                    next++; 
                    q.push(c->left); 
                } 
                if(c->right!=NULL) { 
                    next++; 
                    q.push(c->right); 
                } 
            }
            
            result.insert(result.begin(),temp); 
        } 
        
        return result; 
    }
};