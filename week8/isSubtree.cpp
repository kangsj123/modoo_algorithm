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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool tmp=compareTree(s, t);
        if(tmp)return true;
          
        if(s->left!=NULL){
            tmp=isSubtree(s->left,t);
            if(tmp)return true;
        }
          
        if(s->right!=NULL){
            tmp=isSubtree(s->right,t);
            if(tmp)return true;
        }
        
        return false;
    }
    
    bool compareTree(TreeNode* s, TreeNode* t){
        bool tmp;
        if(s->val != t->val) return false;
        if(s->left!=NULL && t->left==NULL) return false;
        if(s->left==NULL && t->left!=NULL) return false;
        if(s->right!=NULL && t->right==NULL) return false;
        if(s->right==NULL && t->right!=NULL) return false;
        
        if(s->left!=NULL && t->left!=NULL){
            tmp=compareTree(s->left,t->left);
            if(!tmp)return false;
        }
        
        if(s->right!=NULL && t->right!=NULL){
            tmp=compareTree(s->right,t->right);
            if(!tmp)return false;
        }
        
        return true;
    }
};
