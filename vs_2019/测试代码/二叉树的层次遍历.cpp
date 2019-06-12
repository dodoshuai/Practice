#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
class Solution {
public:
	/*vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> a;
		queue<int>b;
		int level = 1;
		if (root) {
			a.push(root);
			b.push(level);
		}
		vector<vector<int>> c;
		while (!a.empty()) {
			TreeNode* node = a.front();
			a.pop();
			level = b.front();
			b.pop();
			c.resize(level);
			c[level - 1].push_back(node->val);
			if (node->left) {
				a.push(node->left);
				b.push(level + 1);
			}
			if (node->right) {
				a.push(node->right);
				b.push(level + 1);
			}
		}
		return c;
	}*/
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode *> a;
		queue<TreeNode *> b;
		if (root) {
			a.push(root);
		}
		vector<vector<int>> vv;
		while (!a.empty() || !b.empty()) {
			vector<int> c;
			if (!a.empty()) {

				while (!a.empty()) {
					TreeNode* node = a.front();
					a.pop();
					c.push_back(node->val);
					//	b.pop();
					//	c[level - 1].push_back(node->val);
					if (node->left) {
						b.push(node->left);
					}
					if (node->right) {
						b.push(node->right);
					}
				}
			}
			else if (!b.empty()) {
				while (!b.empty()) {
					TreeNode* node = b.front();
					b.pop();
					c.push_back(node->val);
					//	b.pop();
					//	c[level - 1].push_back(node->val);
					if (node->left) {
						a.push(node->left);
					}
					if (node->right) {
						a.push(node->right);
					}
				}
			}
			vv.push_back(c);
		}
		return vv;
	}
};