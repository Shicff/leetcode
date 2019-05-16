/**

����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

���磺
���������� [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
�������Ե����ϵĲ�α���Ϊ��

[
  [15,7],
  [9,20],
  [3]
]


��ӣ�������q.push(x); ��x�ӵ����е�ĩ�ˡ�

���ӣ�������q.pop(); �������еĵ�һ��Ԫ�أ�ע�⣬�����᷵�ر�����Ԫ�ص�ֵ��

���ʶ���Ԫ�أ�������q.front()�������类ѹ����е�Ԫ�ء�

���ʶ�βԪ�أ�������q.back()�������ѹ����е�Ԫ�ء�

�ж϶��пգ�������q.empty()�������п�ʱ������true��

���ʶ����е�Ԫ�ظ�����������q.size()
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
        
        if(root == NULL) return result; //��
        
        int cur; 
        int next=1; 
        
        TreeNode* c=root;  //��ָ��
        
        queue<TreeNode*> q; //�Ž�����
        q.push(c);
        
        while(!q.empty())
        { 
            cur=next; 
            next=0; 
            
            vector<int> temp; 
            while(cur>0){
                c=q.front(); //��������Ԫ��
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