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
	
	void quickSort(vector<int>& nums) {
		quickSort(nums, 0, nums.size() - 1);
	}
	void quickSort(vector<int>& nums, int left, int right) {
		if (left >= right) return;
		int p1 = left;
		int p2 = right;
		int pivot = nums[p1];
		while (p1 < p2) {
			while (p1 < p2 && nums[p2] >= pivot) p2--;
			nums[p1] = nums[p2];
			while (p1 < p2 && nums[p1] <= pivot) p1++;
			nums[p2] = nums[p1];
		}
		nums[p1] = pivot;
		quickSort(nums, left, p1 - 1);
		quickSort(nums, p1 + 1, right);
	}
};

