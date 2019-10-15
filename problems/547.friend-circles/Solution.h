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
	
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		int res = n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (M[i][j] == 1) {
					int px = getParent(i,p);
					int py = getParent(j,p);
					if (px != py) {
						p[px] = py;
						res--;
					}
				}
			}
		}
		return res;
	}
	int getParent(int x,vector<int>& parent) {
		if (parent[x] == x) return x;
		else {
			return getParent(parent[x],parent);
		}
	}
};

