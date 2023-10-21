/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> res; //to store final result

    void traverse(TreeNode* root, vector <int> &path, int rem){
        if(!root) return; //return at NULL

        if(!root->left && !root->right){ //leaf node reached
            path.push_back(root->val); //do
            if(rem == root->val) res.push_back(path);
        //if remaining sum is same as value of root we have valid path
            path.pop_back(); // undo
            return;
        }

        int val = root->val; //subtract the contribution of this value from rem (remaining sum)
        path.push_back(val); //do
        traverse(root->left, path, rem-val); //recurse left subtree
        traverse(root->right, path, rem-val); //recurse right subtree
        path.pop_back(); //undo

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear(); //reset res 
        if(!root) return res; //if root itself NULL there are no paths
        vector <int> path; //to store the path
        traverse(root, path, targetSum);
        return res;
    }
};
