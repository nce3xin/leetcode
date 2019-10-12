#include "Solution.h"

int main() {
	Solution* s = new Solution();
	vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
	s->mergeSort(nums);
	return 0;
}