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
	
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image[sr][sc] == newColor) return image;
		dfs(image, sr, sc, image[sr][sc],newColor);
		return image;
	}
	void dfs(vector<vector<int>>& image, int x, int y, int originColor, int newColor) {
		int m = image.size();
		int n = image[0].size();
		if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] != originColor) {
			return;
		}
		image[x][y] = newColor;
		dfs(image, x + 1, y, originColor, newColor);
		dfs(image, x - 1, y, originColor, newColor);
		dfs(image, x , y-1, originColor, newColor);
		dfs(image, x , y+1, originColor, newColor);
	}
};

