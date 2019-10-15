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

class Trie {
private:
	struct TrieNode{
		char c;
		bool isWord;
		vector<TrieNode*> children;
		TrieNode(char _c, bool _isWord=false) :c(_c), isWord(_isWord) {
			for (int i = 0; i < 26; ++i) {
				children.push_back(nullptr);
			}
		}
	};
	TrieNode* root = nullptr;
public:
	Trie() {
		root = new TrieNode(' ');
	}

	void insert(string word) {
		TrieNode* cur = root;
		for (auto c : word) {
			int idx = c - 'a';
			if (cur->children[idx] == nullptr) {
				cur->children[idx] = new TrieNode(c);
			}
			cur = cur->children[idx];
		}
		cur->isWord = true;
	}

	bool search(string word) {
		TrieNode* cur = root;
		for (auto c : word) {
			int idx = c - 'a';
			if (cur->children[idx] == nullptr) return false;
			cur = cur->children[idx];
		}
		if (cur->isWord) {
			return true;
		}
		else return false;
	}

	bool statsWith(string prefix) {
		TrieNode* cur = root;
		for (auto c : prefix) {
			int idx = c - 'a';
			if (cur->children[idx]==nullptr) {
				return false;
			}
			cur = cur->children[idx];
		}
		return true;
	}
};

class Solution
{
public:
	Solution();
	~Solution();
	
	
};

