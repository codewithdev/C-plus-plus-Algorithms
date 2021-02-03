class Solution {
public:
    void mirror(TreeNode*root){
        if(root==NULL){
            return;
        }
        mirror(root->left);
        mirror(root->right);
        TreeNode*temp= root->left;
        root->left= root->right;
        root->right= temp;
    }
    TreeNode* invertTree(TreeNode* root) {
       mirror(root);
        return root;
    }
};
