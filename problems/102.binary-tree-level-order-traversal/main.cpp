#include "Solution.h"

int main() {
	Solution* s = new Solution();
	TreeNode* root = new TreeNode(8);
	TreeNode* n1 = new TreeNode(6);
	TreeNode* n2 = new TreeNode(10);
	TreeNode* n3 = new TreeNode(5);
	TreeNode* n4 = new TreeNode(7);
	TreeNode* n5 = new TreeNode(9);
	TreeNode* n6 = new TreeNode(11);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	//vector<vector<int>> res=s->levelOrder(root);
	vector<int> res = s->levelOrderSimple(root);
	return 0;
}