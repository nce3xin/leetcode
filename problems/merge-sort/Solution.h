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
	
	void mergeSort(vector<int>& nums) {
		mergeSort(nums, 0, nums.size() - 1);
	}
	void mergeSort(vector<int>& nums, int left, int right) {
		if (left >= right) return;
		int mid = left + (right - left) / 2;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
	void merge(vector<int>& nums, int left,int mid, int right) {
		int n1 = mid - left + 1;
		int n2 = right - mid;
		/* create temp arrays */
		vector<int> L(n1);
		vector<int> R(n2);
		/* Copy data to temp arrays L[] and R[] */
		for (int i = 0; i < n1; ++i) {
			L[i] = nums[left + i];
		}
		for (int i = 0; i < n2; ++i) {
			R[i] = nums[mid + 1 + i];
		}
		/* Merge the temp arrays back into nums[l..r]*/
		int i = 0;// Initial index of first subarray 
		int j = 0;// Initial index of second subarray 
		int k = left;// Initial index of merged subarray, int k=left, not zero.
		while (i < n1 && j < n2) {
			if (L[i] < R[j]) {
				nums[k] = L[i];
				i++;
			}
			else {
				nums[k] = R[j];
				j++;
			}
			k++;
		}
		/* Copy the remaining elements of L[], if there
		are any */
		while (i < n1) {
			nums[k] = L[i];
			i++;
			k++;
		}
		/* Copy the remaining elements of R[], if there
		are any */
		while (j < n2) {
			nums[k] = R[j];
			j++;
			k++;
		}
	}
};

