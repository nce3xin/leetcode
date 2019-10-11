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
	
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<ListNode*> s;
		vector<int> res;
		ListNode* p = head;
		while (p) {
			s.push(p);
			p = p->next;
		}
		while (!s.empty()) {
			ListNode* cur = s.top();
			s.pop();
			res.push_back(cur->val);
		}
		return res;
	}
};

