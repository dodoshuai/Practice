#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
bool bg_left(TreeNode* root, TreeNode* p, stack<TreeNode*>& n1) {
	if (root == nullptr) {
		return false;
	}

	n1.push(root);
	if (root == p) {
		return true;
	}

	if (bg_left(root->left, p, n1)==true)
		return true;;
	//bg(root->right);
	if (bg_left(root->right, p, n1) == true) {
		return true;
	}
	
		n1.pop();
	
	return false;
}
/* stack<TreeNode*> bg_right(TreeNode *root,TreeNode *q,stack<TreeNode*> &n2){
	  if(root==NULL){
		 return false;
	 }
	 n1.push_back(root->val);
	 if(root==q){
		 return true;
	 }


	 if(bg(root->right))
		 return true;;
	 //bg(root->right);
	 if(bg(root->left)){
	   return true;
	 }else {
		 nq.pop_back();
	 }
	 return false;
 }
 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	stack<TreeNode*>n3;
	stack<TreeNode*>n2;
	bg_left(root, p, n3);
	bg_left(root, q, n2);
	int l = n3.size();
	int r = n2.size();
	//cout<<l<<" "<<r<<endl;
	if (l > r) {
		while (l > r) {
			n3.pop();
			l--;
		}
	}
	else {
		while (r > l) {
			n2.pop();
			r--;
		}
	}
	cout << l << " " << r << endl;
	while (l && r) {
		//TreeNode* t1=n3.top();
		//TreeNode* t2=n2.top();
		if (n3.top() == n2.top())
			return n3.top();
		else {
			n3.pop();
			n2.pop();
			r--;
			l--;
		}
	}
	return nullptr;
}