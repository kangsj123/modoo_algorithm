/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    int index;
    int size;
    vector<int>bst;
    BSTIterator(TreeNode* root) {
        size=0;
        index=-1;
        if(root!=NULL)
            init(root);
    }
    
    void init(TreeNode* node){
        if(node->left!=NULL)
            init(node->left);
        bst.push_back(node->val);
        size++;
        if(node->right!=NULL)
            init(node->right); 
    }
    
    /** @return the next smallest number */
    int next() {
        return bst[++index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(size>index+1)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
