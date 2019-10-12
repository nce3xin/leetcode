#pragma once
#include<vector>
#include<stack>
#include<algorithm>
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
	
	int maxSubArray(vector<int>& nums) {
		int curMaxSum = nums[0];
		int maxSum = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			curMaxSum = max(curMaxSum + nums[i], nums[i]);
			maxSum = max(maxSum, curMaxSum);
		}
		return maxSum;
	}
};

