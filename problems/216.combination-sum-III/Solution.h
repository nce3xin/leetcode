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
	
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> candidate;
		backtrack(res, candidate, k, n,1);
		return res;
	}
	void backtrack(vector<vector<int>>& res, vector<int>& candidate, int k, int sum,int start) {
		if (candidate.size() == k && sum == 0) {
			res.push_back(candidate);
			return;
		}
		for (int i = start; i <= 9; ++i) {
			candidate.push_back(i);
			backtrack(res, candidate, k, sum - i,i+1);
			candidate.pop_back();
		}
	}
};

