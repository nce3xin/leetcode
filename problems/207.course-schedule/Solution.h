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
	
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> indegree(numCourses,0);
		vector<vector<int>> adj(numCourses,vector<int>());
		// build adjacency list and indegree
		for (int i = 0; i < prerequisites.size(); ++i) {
			int in=prerequisites[i][1];
			int out= prerequisites[i][0];
			adj[in].push_back(out);
			indegree[out]++;
		}
		// build zeroIndegree
		deque<int> zeroIndegree;
		for (int i = 0; i < numCourses; ++i) {
			if (indegree[i] == 0) zeroIndegree.push_back(i);
		}
		while (!zeroIndegree.empty()) {
			int cur = zeroIndegree.front();
			zeroIndegree.pop_front();
			numCourses--;
			for (auto next:adj[cur]) {
				if (--indegree[next] == 0) zeroIndegree.push_back(next);
			}
		}
		return numCourses == 0;
	}
};

