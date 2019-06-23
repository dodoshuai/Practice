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
        queue<TreeNode*> nodeq;
        queue<int> levelq;
        
        if(root)
        {
            nodeq.push(root);
            levelq.push(1);
        }
        
        vector<vector<int>> vv;
        while(!nodeq.empty())
        {
            TreeNode* node = nodeq.front();
            nodeq.pop();
            int level = levelq.front();
            levelq.pop();
            
            vv.resize(level);
            vv[level-1].push_back(node->val);
            
            if(node->left)
            {
                nodeq.push(node->left);
                levelq.push(level+1);
            }
            
             if(node->right)
            {
                nodeq.push(node->right);
                levelq.push(level+1);
            }
            
        }
        
        return vv;
    }
};
//-----------------------------------------------------------

???????(863241056) 2019/6/10 21:47:53
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
        queue<TreeNode*> nodeq;
        queue<int> levelq;
        
        if(root)
        {
            nodeq.push(root);
            levelq.push(1);
        }
        
        vector<vector<int>> vv;
        while(!nodeq.empty())
        {
            TreeNode* node = nodeq.front();
            nodeq.pop();
            int level = levelq.front();
            levelq.pop();
            
            vv.resize(level);
            vv[level-1].push_back(node->val);
            
            if(node->left)
            {
                nodeq.push(node->left);
                levelq.push(level+1);
            }
            
             if(node->right)
            {
                nodeq.push(node->right);
                levelq.push(level+1);
            }
            
        }
        
        return vv;
    }
};
//-----------------------------------------------------------
https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

//-----------------------------------------------------------


https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if(root == nullptr)
            return false;
        
        path.push(root);
        if(root == x)
            return true;
        
        if(GetPath(root->left, x, path) == true)
            return true;
        
        if(GetPath(root->right, x, path) == true)
            return true;
        
        path.pop();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> ppath;
        stack<TreeNode*> qpath;
        GetPath(root, p, ppath);
        GetPath(root, q, qpath);
        
        while(ppath.size() != qpath.size())
        {
            if(ppath.size() > qpath.size())
                ppath.pop();
            else
                qpath.pop();
        }
        
        while(ppath.top() != qpath.top())
        {
            ppath.pop();
            qpath.pop();
        }
        
        return ppath.top();
    }
};

