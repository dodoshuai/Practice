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
    TreeNode *pre=NULL;
    bool isValidBST(TreeNode* root) {
        if(!root)
        return true;
       return inorder(root);
        
    }
    
    bool inorder(TreeNode* root) {//*& 针对全部的pre都会改变，* 只改变当前层和下层，对上层无影响
       if (!root) return true;
        bool flag = inorder(root->left);
            //pre=root;
        if (!flag) return false;
        if (pre) {
            if (root->val <= pre->val) return false;
        }
        pre = root;
       return inorder(root->right);
    }
    //  bool isValidBST(TreeNode* root) {
    //     if (!root) return true;
    //     vector<int> vals;
    //     inorder(root, vals);
    //     for (int i = 0; i < vals.size() - 1; ++i) {
    //         if (vals[i] >= vals[i + 1]) return false;
    //     }
    //     return true;
    // }
    // void inorder(TreeNode* root, vector<int>& vals) {
    //     if (!root) return;
    //     inorder(root->left, vals);
    //     vals.push_back(root->val);
    //     inorder(root->right, vals);
    // }
};
