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
//     bool isSymmetric(TreeNode* root) {//�������зֱ������Һ������˳�򽫶����������洢�����������ף����бȽ� 
//         if(root==NULL)//Ϊ�� 
//             return true;
//         TreeNode* p1=root;
//         TreeNode* p2=root;
        
      
//              if(!p1->left&&!p1->right)//�ж����Һ��ӽڵ� 
//             return true;
        
//             queue<TreeNode *> left,right;
//              left.push(p1->left);//���ĺ��ӽڵ� 
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
    bool AtoA(TreeNode* rt1,TreeNode* rt2){//���еݹ�˫�ݹ飬���������ң����������� 
        if(!rt1&&!rt2)// �ų�rt1��rt2��Ϊ�յ����� 
            return true;
        else if(!rt1||!rt2)//�ų���ֻ��һ����Ϊ�յ����� 
            return false;
        if(rt1->val!=rt2->val)//�Ƚ� 
            return false;
       return AtoA(rt1->left,rt2->right)&&AtoA(rt2->left,rt1->right);//
        
    }
    
    bool isSymmetric(TreeNode* root){
        if(!root)//�ų�root==NULL 
            return true;
        return AtoA(root->left,root->right);//�������� 
    }
};
