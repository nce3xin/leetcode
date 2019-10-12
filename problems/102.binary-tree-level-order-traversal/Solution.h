#pragma once
#include<vector>
#include<stack>
#include<algorithm>
#include<deque>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution
{
public:
	Solution();
	~Solution();
	
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		deque<TreeNode*> q; //double ended queue
		q.push_back(root);
		vector<int> line; //record each level
		while (!q.empty()) {
			int levelNum = q.size();
			for (int i = 0; i < levelNum; ++i) {
				if (q.front()->left) q.push_back(q.front()->left);
				if (q.front()->right) q.push_back(q.front()->right);
				line.push_back(q.front()->val);
				q.pop_front();
			}
			res.push_back(line);
			line.clear();
		}
		return res;
	}

	vector<int> levelOrderSimple(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		deque<TreeNode*> q;
		q.push_back(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop_front();
			if (node->left) q.push_back(node->left);
			if (node->right) q.push_back(node->right);
			res.push_back(node->val);
		}
		return res;
	}
};

