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
    // time complexity : O(N);
    // space complexity : O(H);

    int orderNum=0;
    TreeNode* preNode;
    TreeNode *swapNode1,*swapNode2;
public:
    void recoverTree(TreeNode* root) {
        inorderTraverse(root);
        swap(swapNode1->val,swapNode2->val);
    }
    void inorderTraverse(TreeNode* &curNode){
        if(curNode->left!=NULL)inorderTraverse(curNode->left);
        if(++orderNum>1 && preNode->val> curNode->val){
            if(swapNode1)
                swapNode2=curNode;
            else{
                swapNode1=preNode;
                swapNode2=curNode;
            }
        }
        preNode=curNode;
        if(curNode->right!=NULL)inorderTraverse(curNode->right);
    }
};
