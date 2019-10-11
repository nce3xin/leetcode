#pragma once
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	Solution();
	~Solution();
	
	// Recursion method
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
	void inorder(TreeNode* root, vector<int>& res) {
		if (!root) return;
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}

	// Iteration method
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> todo;
		vector<int> res;
		while(root || !todo.empty()){
			while(root){
				todo.push(root);
				root=root->left;
			}
			root=todo.top();
			todo.pop();
			res.push_back(root->val);
			root=root->right;
		}
		return res;
	}
};

