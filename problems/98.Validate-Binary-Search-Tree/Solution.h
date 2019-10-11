#pragma once
#include<vector>
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
	bool isValidBST(TreeNode* root) {
		TreeNode* prev = nullptr;
		return validInorder(root, prev);
	}
	bool validInorder(TreeNode* root, TreeNode*& prev) {
		if (!root)
			return true;
		if (!validInorder(root->left, prev))
			return false;
		if (prev && prev->val >= root->val)
			return false;
		prev = root;
		if (!validInorder(root->right, prev))
			return false;
		return true;
	}
};

