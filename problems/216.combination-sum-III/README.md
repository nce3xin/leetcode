## 题意
从[1, 9]中取k个数，使其和等于n。求满足要求的所有组合。
## 思路
回溯法。为了不重复，每次从上次取数的下一个取。记得candidate.pop_back()。