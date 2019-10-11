#include "Solution.h"

int main() {
	Solution* s = new Solution();
	vector<int> nums = {1,4,5,2,0,9,6};
	s->quickSort(nums);
	return 0;
}