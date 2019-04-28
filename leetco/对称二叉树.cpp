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
//     bool isSymmetric(TreeNode* root) {//两个队列分别按照左右和右左的顺序将二叉树子树存储，并弹出队首，进行比较 
//         if(root==NULL)//为空 
//             return true;
//         TreeNode* p1=root;
//         TreeNode* p2=root;
        
      
//              if(!p1->left&&!p1->right)//判断左右孩子节点 
//             return true;
        
//             queue<TreeNode *> left,right;
//              left.push(p1->left);//根的孩子节点 
//             right.push(p2->right);
//         while(!left.empty()||!right.empty()){
//             p1=left.front();
//             p2=right.front();
//                 left.pop();
//                 right.pop();
//             if(!p1&&!p2)
//                 continue;
//                else if(!p1||!p2)
//                     return false;
//             else if(p1->val!=p2->val)
//                 return false;
            
                
//                 left.push(p1->left);
//                 right.push(p2->right);
//                 left.push(p1->right);
//                 right.push(p2->left);
//         }
//         return true;
//     }
    bool AtoA(TreeNode* rt1,TreeNode* rt2){//进行递归双递归，左子树左右，右子树右左 
        if(!rt1&&!rt2)// 排除rt1和rt2都为空的条件 
            return true;
        else if(!rt1||!rt2)//排除有只有一个不为空的条件 
            return false;
        if(rt1->val!=rt2->val)//比较 
            return false;
       return AtoA(rt1->left,rt2->right)&&AtoA(rt2->left,rt1->right);//
        
    }
    
    bool isSymmetric(TreeNode* root){
        if(!root)//排除root==NULL 
            return true;
        return AtoA(root->left,root->right);//左右子树 
    }
};
